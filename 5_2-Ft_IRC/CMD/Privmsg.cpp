#include "../Server.hpp"

void Server::ircPRIVMSG(int client_fd, const std::vector<std::string> &params) {
    if (params.size() < 3) {
        sendError(client_fd, "461", "PRIVMSG :Not enough parameters");
        return;
    }

    std::string target = params[1];
    std::string message = "";
    for (size_t i = 2; i < params.size(); ++i) {
        message += (i > 2 ? " " : "") + params[i];
    }
		if (findChannelIntoServer(target))
		{
			Channel *channelSelec = findChannelIntoServer(target);
			std::vector<int> listFdChannel = channelSelec->getClientFds();
			if (findValueInVector(listFdChannel, client_fd) == false) {
				sendError(client_fd, "442", params[1] + " :You're not on that channel\r\n");
				return ;
			}
		}
    if (target[0] == '#') {
        bool channelFound = false;
        for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
            if (it->getName() == target) {
                channelFound = true;
                std::string senderNick = _clients[client_fd].getNickname();
                std::string senderUser = _clients[client_fd].getUsername();
                std::string senderHost = _clients[client_fd].getHostname();
                std::string formatted_message = ":" + senderNick + "!" + senderUser + "@" + senderHost + " PRIVMSG " + target + " " + message + "\r\n";
                const std::vector<int>& clients = it->getClientFds();
                for (std::vector<int>::const_iterator ci = clients.begin(); ci != clients.end(); ++ci) {
                    if (*ci != client_fd) {
                        send(*ci, formatted_message.c_str(), formatted_message.length(), 0);
                    }
                }
                break;
            }
        }
        if (!channelFound) {
            sendError(client_fd, "403", target + " :No such channel");
        }
    } else {
        bool userFound = false;
        for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
            if (it->second.getNickname() == target) {
                std::string senderNick = _clients[client_fd].getNickname();
                std::string senderUser = _clients[client_fd].getUsername();
                std::string senderHost = _clients[client_fd].getHostname();
                std::string formatted_message = ":" + senderNick + "!" + senderUser + "@" + senderHost + " PRIVMSG " + target + " " + message + "\r\n";
                send(it->first, formatted_message.c_str(), formatted_message.length(), 0);
                userFound = true;
                break;
            }
        }
        if (!userFound) {
            sendError(client_fd, "401", target + " :No such nick");
        }
    }
}
