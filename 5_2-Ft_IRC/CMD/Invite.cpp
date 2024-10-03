/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:23:12 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 15:53:45 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"

bool Server::findValueInVector(const std::vector<int>& vec, int value) {
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		// std::cout << "valeur it : " << *it << " - value look for " << value << std::endl;
		if (*it == value)
			return true;
	}
	return false;
}

// INVITE - Inviter un client au channel - /invite <channel> <nickname> -->
void Server::ircINVITE(int client_fd, const std::vector<std::string>& params)
{
	// std::cout << params.size() << " " << params[1][0] << " inside invite\n";
	if (params.size() < 3) {
		sendError(client_fd, "461", " :Not enough parameters\r\n");
		return;
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
	Client buyer = GetClient(client_fd);
	// channelSelec.setInviteOnly(true);
	// std::cout << "Nick: " << buyer.getNickname() <<" invite restriction: " << channelSelec->getRestrictInvite() << " is channel op: " << buyer.isChannelOp(channelName) << " is global op: " << buyer.isGlobalOp() << std::endl;
	if (channelSelec->getRestrictInvite() == true) {
		if (buyer.isGlobalOp() == false && buyer.isChannelOp(channelName) == false && channelSelec->isOperator(client_fd)) {
			// std::cout << "invite restriction\n";
			sendError(client_fd, "482", params[1] + " :that channel has invite restriction\r\n");
			return ;
		}
	}
	if (channelSelec->getUserLimit() == (int)channelSelec->getClientFds().size()) {
		// std::cout << "invite size restriction\n";
		sendError(client_fd, "482", params[1] + " :size limit of that channel is reached\r\n");
		return ;
	}
	Client client = *findnicknameIntoClient(params[2]);
	if (findValueInVector(listFdChannel, client.getFd()) == true) {
		// std::cout << "already in channel\n";
		sendError(client_fd, "443", params[1] + " :the client " + client.getNickname() + " is already in the channel " + channelName + "\r\n");
		return ;
	}
	client.AddChannelInvite(channelName);
	channelSelec->addInvite(client.getFd());
	// std::cout << "user add ok\n";
	std::string msg1 = ":341 " + buyer.getNickname() + " has successfully invite " + client.getNickname() + " in " + channelName + " channel\r\n";
	sendMsg(msg1, client_fd); // msg buyer
	std::string msg2 = ":" + buyer.getNickname() + " INVITE " + client.getNickname() + " " + channelName + "\r\n";
	sendMsg(msg2, client.getFd()); // msg client
}

