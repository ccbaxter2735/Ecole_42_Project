/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:34:12 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 19:12:05 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Server.hpp"

void Server::ircKICK(int client_fd, const std::vector<std::string>& params) {
	Client buyer = GetClient(client_fd);
	
	// std::cout << "inside kick\n";
	if (params.size() < 2) {
		sendError(client_fd, "461", " :Not enough parameters\r\n");
		return;
	}
	std::string reason = "";
	if (params.size() > 2) {
		if (params.size() > 3)
			reason = params[3];
		if (buyer.isChannelOp(params[1]) == false) {
			if (buyer.isGlobalOp() == false) {
				sendError(client_fd, "482", params[1] + " :cannot kick someone if you're not operator\r\n");
				return ;
			}
		}
		std::string channelName = params[1];
		if (params[1][0] != '#' || !findChannelIntoServer(channelName)) {
			// std::cout << "wrong server name\n";
			sendError(client_fd, "403", params[1] + " :Channel's name doesn't begin by # or is not in the server\r\n");
			return;
		}
		if (!findnicknameIntoClient(params[2])) {
			// std::cout << "not in server\n";
			sendError(client_fd, "442", params[1] + " :the client specified doesn't exit\r\n");
			return ;
		}
		Channel *channelSelec = findChannelIntoServer(channelName);
		std::vector<int> listFdChannel = channelSelec->getClientFds();
		if (findValueInVector(listFdChannel, client_fd) == false) {
			// std::cout << "buyer not in channel\n";
			sendError(client_fd, "442", params[1] + " :You're not on that channel\r\n");
			return ;
		}
		Client client = *findnicknameIntoClient(params[2]);
		if (findValueInVector(listFdChannel, client.getFd()) == false) {
			// std::cout << "already outside channel\n";
			sendError(client_fd, "441", params[1] + " :the client " + client.getNickname() + " is already out the channel " + channelName + "\r\n");
			return ;
		}
		std::vector<int> list = channelSelec->getClientFds();
		// std::cout << "before valeur it:";
		// for (std::vector<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
		// 	std::cout << " " << *it << std::endl;}
		channelSelec->removeClient(client.getFd());
		channelSelec->removeInvite(client.getFd());
		list = channelSelec->getClientFds();
		// std::cout << "\nafter valeur it:";
			for (std::vector<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
			std::cout << " " << *it << std::endl;}
		// std::cout << "\nuser remove ok\n";
		std::string msg1 = ":localhost " + buyer.getNickname() + " has successfully kicked " + client.getNickname() + " out " + channelName + " channel\r\n";
		sendMsg(msg1, client_fd); // msg buyer
		std::string msg2 = ":" + buyer.getNickname() + "!" + buyer.getUsername() + "@" + buyer.getHostname() + " KICK " + channelName + " " + client.getNickname() + " " + reason + "\r\n";
		sendMsg(msg2, client.getFd()); // msg client
	}
}
