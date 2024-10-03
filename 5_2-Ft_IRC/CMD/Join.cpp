/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:08:12 by terussar          #+#    #+#             */
/*   Updated: 2024/09/05 16:20:45 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"

static bool    findComma(const std::string s){
    return s.find(',') != std::string::npos;
}

static std::vector<std::string> splitComma(const std::string &strWithComma){
    std::vector<std::string> res;
    size_t start;
    size_t end = 0;

    while ((start = strWithComma.find_first_not_of(',', end)) != std::string::npos){
            end = strWithComma.find(',', start);
            res.push_back(strWithComma.substr(start, end - start));
    }
    return res;
}

static bool checkValidChName(const std::string &chName){
    if (chName.empty() || (chName[0] != '#' && chName[0] != '$'))
        return false;
    const char InvalidChars[] = { ' ', ',', '*', '?', '!', '@', '.' };
    const size_t InvalidCharsSize = sizeof(InvalidChars) / sizeof(InvalidChars[0]);
    for (size_t i = 0; i < chName.size(); ++i) {
        for (size_t j = 0; j < InvalidCharsSize; ++j) {
            if (chName[i] == InvalidChars[j])
                return false;
        }
    }
    return true;
}

void Server::ircJOIN(int client_fd, const std::vector<std::string> &params) {
	std::vector<Channel>::iterator it;
	if (params.size() < 2) {
		sendError(client_fd, "461", " :Not enough parameters\r\n");
		return;
	}
    std::vector<std::string> channelNames;
    std::string providedPassword = (params.size() > 2 ) ? params[2] : "";
    if (findComma(params[1]))
        channelNames = splitComma(params[1]);
    else
        channelNames.push_back(params[1]);
    
    for (size_t i = 0; i < channelNames.size(); ++i) {
        std::string chanName = channelNames[i];
        if (!checkValidChName(chanName)){
            SendBuffer = ":localhost 403 "  + _clients[client_fd].getNickname() + " " + chanName + " :No such channel\r\n";
            sendToClient(client_fd, SendBuffer);
            continue;
        }
        for (it = _channels.begin(); it != _channels.end(); ++it) {
            // std::cout << "\033[32mIN JOING: GET CHANNEL NAME\033[0m"  << it->getName() << std::endl;
            if (it->getName() == chanName) {
								std::vector<int> listFdChannel = it->getClientFds();
								if (it->findnicknameIntoChannel(client_fd)){
									sendError(client_fd, " ", chanName + " :You're already in the channel");
									break;
                }
                else if (it->getInviteOnly() && !it->isOperator(client_fd) && !it->isInvited(client_fd)){
                    std::string serverName = "localhost";
                    SendBuffer = ":" + serverName + " 473 " + _clients[client_fd].getNickname() + " " + chanName + " :Cannot join channel (+i)\r\n";
                    sendToClient(client_fd, SendBuffer);

                    std::cout << "invite only triggered" << std::endl;
                    break;
                }
                else if (!it->getPassword().empty() && it->getPassword() != providedPassword) {
                        sendError(client_fd, "475", chanName + " :Cannot join channel (+k) - Wrong password");
                    break;
                }
                else if (it->getUserLimit() > 0 && static_cast<int>(it->getClientFds().size()) >= it->getUserLimit()){
                    sendError(client_fd, "471", chanName + " :Cannot join channel (+l) - Channel full");
                    break;
                }
                else {
                    it->addClient(client_fd);
                    // std::cout << "\033[31mSEND MSG\033[0m:  " << std::endl;
                    SendBuffer = ":" + _clients[client_fd].getNickname() + "!~" + _clients[client_fd].getUsername() + "@localhost JOIN :" + chanName + "\r\n";
                    sendToClient(client_fd, SendBuffer);
                    SendBuffer = ":localhost 353 " + _clients[client_fd].getNickname() + " = " + chanName + " :@" + _clients[client_fd].getNickname() + "\r\n";
                    sendToClient(client_fd, SendBuffer);
                    SendBuffer = ":localhost 366 " + _clients[client_fd].getNickname() + " " + chanName + " :End of /NAMES list.\r\n";
                    sendToClient(client_fd, SendBuffer);
                    std::cout << "Client FD " << client_fd << " joined channel " << chanName << std::endl;
                    break;
                }
            }
        }

        if (it == _channels.end()) {
            Channel newChannel(chanName, "");
            newChannel.addClient(client_fd);
            this->_channels.push_back(newChannel);
            // std::cout << "\033[31mSEND MSG\033[0m:  " << std::endl;
            SendBuffer = ":" + _clients[client_fd].getNickname() + "!~" + _clients[client_fd].getUsername() + "@localhost JOIN :" + chanName + "\r\n";
            sendToClient(client_fd, SendBuffer);
            SendBuffer = ":localhost 353 " + _clients[client_fd].getNickname() + " = " + chanName + " :@" + _clients[client_fd].getNickname() + "\r\n";
            sendToClient(client_fd, SendBuffer);
            SendBuffer = ":localhost 366 " + _clients[client_fd].getNickname() + " " + chanName + " :End of /NAMES list.\r\n";
            sendToClient(client_fd, SendBuffer);
            std::cout << "Client FD " << client_fd << " joined channel " << chanName << std::endl;
        }
    }
}
