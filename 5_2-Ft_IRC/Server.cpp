/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:36:49 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 15:37:34 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Client Server::GetClient(int fd) {
	std::map<int, Client>::iterator it;
	
	for(it = this->_clients.begin(); it != this->_clients.end(); it++) {
		if (it->first == fd)
			return (it->second);
	}
	return NULL;
}


void Server::sendErrC(int code, std::string clientname, std::string channelname, int fd, std::string msg)
{
	std::stringstream ss;
	ss << ":localhost " << code << " " << clientname << " " << channelname << " " << msg;
	std::string resp = ss.str();
    std::cout <<  "\033[33m[Server]\033[0m " << resp << std::endl;
	if(send(fd, resp.c_str(), resp.size(),0) == -1)
		std::cerr << "send() faild" << std::endl;
}

void Server::sendErr(int code, std::string clientname, int fd, std::string msg)
{
	std::stringstream ss;
	ss << ":localhost " << code << " " << clientname << " " << msg;
	std::string resp = ss.str();
    std::cout <<  "\033[33m[Server]\033[0m " << resp << std::endl;
	if(send(fd, resp.c_str(), resp.size(),0) == -1)
		std::cerr << "send() faild" << std::endl;
}

void Server::sendMsg(std::string response, int fd)
{
    std::cout <<  "\033[33m[Server]\033[0m " << response << std::endl;
    ssize_t bytes_sent = send(fd, response.c_str(), response.length(), 0);
    if (bytes_sent == -1) {
        std::cerr << "Error sending message to client: " << strerror(errno) << std::endl;
    } else if (static_cast<size_t>(bytes_sent) < response.length()) {
        std::cerr << "Warning: Not all bytes were sent to the client" << std::endl;
    }
}

void Server::listChaine( void )
{
	std::vector<Channel>::iterator it;
		
	std::cout << "liste channel\n";
	for(it = this->_channels.begin(); it != this->_channels.end(); it++) {
		std::cout << it->getName() << "\n";
	}
}

void Server::broadcast(const std::string& message, int sender_fd) {
    std::map<int, Client>::const_iterator it;
    for (it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->first != sender_fd) {
            send(it->first, message.c_str(), message.length(), 0);
        }
    }
}

std::vector<std::string> Server::_splitCommand(std::string &command) {
    std::vector<std::string> cmdTable;
    size_t start;
    size_t end = 0;

    while ((start = command.find_first_not_of(' ', end)) != std::string::npos) {
        end = command.find(' ', start);
        if (command[start] == ':'){
            cmdTable.push_back(command.substr(start));
            break ;
        } else {
            cmdTable.push_back(command.substr(start, end - start));
        }
    }
    return cmdTable;
}

std::vector<std::string> Server::parseCommand(std::string &command) {
    return _splitCommand(command);
}

bool Server::isValidCommand(const std::string &command) {
    static const char* commands[] = {"CAP", 
                                    "NICK",
                                    "USER",
                                    "PING",
                                    "PRIVMSG",
                                    "JOIN",
                                    "KICK",
                                    "INVITE",
                                    "TOPIC",
                                    "MODE",
                                    "PASS",
                                    "PART",
                                    "QUIT",
                                    "OPER",
                                    "WHO",
									"WHOIS"
    };
    static const std::set<std::string> validCommands(commands, commands + sizeof(commands) / sizeof(commands[0]));
    return validCommands.find(command) != validCommands.end();
}

void Server::processInvalidCommand(int client_fd, const std::string &command) {
    SendBuffer = ERR_421(_clients[client_fd].getNickname(), command);
    sendToClient(client_fd, SendBuffer);
}

void Server::processCommand(int client_fd, const std::vector<std::string> &cmdVector) {
    if (_clients.find(client_fd) == _clients.end()) {
        std::cerr << "Attempt to process command for non-existent client FD: " << client_fd << std::endl;
        return;
    }

    if (cmdVector.empty() || !isValidCommand(cmdVector[0])) {
        std::cout << "Invalid command from FD " << client_fd << std::endl;
        processInvalidCommand(client_fd, cmdVector[0]);
    } else {
        //std::cout << "line: 195: Processed command from FD " << client_fd << ": " << cmdVector[0] << std::endl;

        if (cmdVector[0] != "PASS" && cmdVector[0] != "CAP" && !_clients[client_fd].isAuthed()) {
            std::string msg = "You are not authed.\r\n";
            send(client_fd, msg.c_str(), msg.length(), 0);
            close(client_fd);
            client_buffers.erase(client_fd);
            _clients.erase(client_fd);
            std::cout << "Unauthed Client disconnected: FD " << client_fd << std::endl;
            return;
        }
        
        /*print recieved msg*/
        printParams(cmdVector);

        if (cmdVector[0] == "NICK") {
            ircNICK(client_fd, cmdVector);
        } else if (cmdVector[0] == "JOIN") {
					// std::cout << "in join\n";
            ircJOIN(client_fd, cmdVector);
        } else if (cmdVector[0] == "USER") {
            ircUSER(client_fd, cmdVector);
        } else if (cmdVector[0] == "PING") {
            ircPONG(client_fd, cmdVector);
        } else if (cmdVector[0] == "PART") {
            ircPART(client_fd, cmdVector);
        } else if (cmdVector[0] == "QUIT") {
            ircQUIT(client_fd, cmdVector);
        } else if (cmdVector[0] == "OPER") {
            ircOPER(client_fd, cmdVector);
        } else if (cmdVector[0] == "PRIVMSG") {
            ircPRIVMSG(client_fd, cmdVector);
        } else if (cmdVector[0] == "KICK") {
            ircKICK(client_fd, cmdVector);
        } else if (cmdVector[0] == "INVITE") {
					// std::cout << "in invite\n";
            ircINVITE(client_fd, cmdVector);
        } else if (cmdVector[0] == "TOPIC") {
					// std::cout << "in topic\n";
            ircTOPIC(client_fd, cmdVector);
        } else if (cmdVector[0] == "MODE") {
            ircMODE(client_fd, cmdVector);
        } else if (cmdVector[0] == "WHO") {
            ircWHO(client_fd, cmdVector);
        } else if (cmdVector[0] == "WHOIS") {
            ircWHOIS(client_fd, cmdVector);
        } else if (cmdVector[0] == "PASS") {
            ircPASS(client_fd, cmdVector);
        } else if (cmdVector[0] == "CAP") {
        } else {
            std::cout << "Unexpected command from FD " << client_fd << ": " << cmdVector[0] << std::endl;
            processInvalidCommand(client_fd, cmdVector[0]);
        }
    }
}

void    Server::printParams(const std::vector<std::string> &cmdTable) const {
    std::cout << "\n----COMMAND VECTOR----" << std::endl;
    for(int i = 0; i < (int)cmdTable.size(); ++i)
        std::cout << "Vector " << i << ": " << cmdTable[i] << std::endl;
    std::cout << "---- END  PRINT  ----\n" << std::endl;
}

void    Server::sendToClient(int client_fd, std::string msg) {
    std::cout <<  "\033[33m[Server]\033[0m " << msg << std::endl;
    send(client_fd, msg.c_str(), msg.length(), 0);
}

void    Server::printClientStatus(int client_fd) const {
    std::map<int, Client>::const_iterator it = _clients.find(client_fd);
    if (it != _clients.end()) {
        const Client &client = it->second;
        std::cout << "-----\n" 
        << "Client FD: " << client_fd << "\n"
        << "Username: " << client.getUsername() << "\n"
        << "Realname: " << client.getRealname() << "\n"
        << "Nickname: " << client.getNickname() << "\n"
        << "Hostname: " << client.getHostname() << "\n"
        << "Servername: " << client.getServername() << "\n"
        << "Is Global Operator: " << client.isGlobalOp() << "\n"
        << "-------\n" << std::endl;
    } else {
        std::cerr << "Non-existent client FD: " << client_fd << std::endl;
        return;
    }

}
