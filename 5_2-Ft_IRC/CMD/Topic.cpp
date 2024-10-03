/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:49:04 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 15:48:42 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"
#include "../Channel.hpp"

std::string Server::timeTopic()
{
	time_t current = time(NULL);
	std::stringstream time;

	time << current;
	return time.str();
}

void Server::ircTOPIC(int client_fd, const std::vector<std::string>& params) {
	std::string msg;
	
	// std::cout << "in topic\n" << std::endl;
	if (params.size() < 2) {
		sendError(client_fd, "461", " :Not enough parameters\r\n");
		return;
	}
	std::string channelName = params[1];
	//std::cout << "restrict " << findChannelIntoServer(channelName)->getTopicRestriction() << std::endl;
	if (params[1][0] != '#' || !findChannelIntoServer(channelName)) {
		// std::cout << "wrong server name\n";
		sendError(client_fd, "403", " :Channel's name doesn't begin by # or is not in the server\r\n");
		return;
	}
	Channel *channelSelec = findChannelIntoServer(channelName);
	std::cout << "view topic : " << channelSelec->getTopic() << std::endl;
	std::vector<int> listFdChannel = channelSelec->getClientFds();
	if (findValueInVector(listFdChannel, client_fd) == false) {
		// std::cout << "client not in channel\n";
		sendError(client_fd, "442", params[1] + " :You're not on that channel\r\n");
		return ;
	}
	if (params.size() == 2) {
		if (channelSelec->getTopic() == "") {
			// std::cout << "no topic set\n";
			sendError(client_fd, "331", params[1] + " :No topic is set\r\n");
			return;
		}
		else {
			std::string msg1 = ": 332 " + GetClient(client_fd).getNickname() + " " + channelName + " " + channelSelec->getTopic() + "\r\n";
			sendMsg(msg1, client_fd);
			std::string msg2 = ": 333 " + GetClient(client_fd).getNickname() + " " + channelName + " " + GetClient(client_fd).getNickname() + " " + channelSelec->GetTime() + "\r\n";
			sendMsg(msg2, client_fd);
			return ;
		}
	}
	if (params.size() == 3) {
		if (params[2].size() > 80) {
			// std::cout << "too long msg\n";
			sendError(client_fd, "482", params[1] + " :new topic is too long, 80 characters max allowed, try again\r\n");
			return;
		}
		if (params[2][0] == ':' && params[2][0] == '\0') {
			sendError(client_fd, "331", params[1] + " :No topic is set\r\n");
			return;
		}
		if (channelSelec->getRestrictTopic() == true) {
			// std::cout << "topic restriction\n";
			if (GetClient(client_fd).isChannelOp(channelName) == false && GetClient(client_fd).isGlobalOp() == false && channelSelec->isOperator(client_fd) == false) {
				sendError(client_fd, "482", params[1] + " :" + channelName + " has a topic's restriction, you cannot change it\r\n");
				return ;
			}
		}
		// std::string newTopic = params[2][0] == ':' ? params[2].substr(1) : params[2]; // pb with this line, topic return only first word
		std::string newTopic = params[2];
		// std::cout << "affichage new topic : " << newTopic << " - param 2: " << params[2] << std::endl;
		channelSelec->setTopic(newTopic);
		// std::cout << "verif settopic: " << channelSelec->getTopic() << std::endl;
		channelSelec->setTime(timeTopic());
		
		msg = ":" + _clients[client_fd].getNickname() + "!" + _clients[client_fd].getUsername() + "@localhost TOPIC " + channelName + " " + channelSelec->getTopic() + "\r\n";
		// send(client_fd, msg.c_str(), msg.length(), 0);
		// std::cout << "topic changed ok\n" << msg << std::endl;
		channelSelec->sendAllFd(msg);
	}
}