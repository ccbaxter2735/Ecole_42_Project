/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:45:10 by terussar          #+#    #+#             */
/*   Updated: 2024/09/05 11:36:55 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"

// check if a client's nickname given by user exists in the server
Client *Server::findnicknameIntoClient(std::string nickname) {
	std::map<int, Client>::iterator it;
	
	for(it = this->_clients.begin(); it != this->_clients.end(); it++) {
		if (it->second.getNickname() == nickname)
			return &it->second;
	}
	return NULL;
}

// check if a channel's name given by user exists in the server
Channel *Server::findChannelIntoServer(std::string channelName) {
	
	std::vector<Channel>::iterator it;

  for(it = this->_channels.begin(); it != this->_channels.end(); ++it) {
		// std::cout << "-- " << it->getName() << " -- " << channelName << " -- " << std::endl;
		if (it->getName() == channelName) {
			return &(*it);
		}
	}
  return (NULL);
}

void Server::sendError(int client_fd, const std::string& code, const std::string& message) {
	std::string error_message = ":localhost " + code + " " + message + "\r\n";
	std::cout <<  "\033[33m[Server]\033[0m " << error_message << std::endl;
	send(client_fd, error_message.c_str(), error_message.size(), 0);
}

void Channel::sendAllFd(std::string msg)
{
	for(size_t i = 0; i < _clientFds.size(); i++) {
		if(send(this->_clientFds[i], msg.c_str(), msg.size(),0) == -1)
			std::cerr << "send() faild" << std::endl;
	}
}
