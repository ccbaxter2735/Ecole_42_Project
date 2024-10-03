/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:22:21 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 19:56:56 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"

void Server::ircMODE(int client_fd, const std::vector<std::string> &params)
{
	if (params.size() < 2)
	{
		sendError(client_fd, "461", ":Not enough parameters");
		return;
	}
	if (params[1][0] == '#')
		channelMode(client_fd, params);
	else
		userMode(client_fd, params);
}

void Server::userMode(int client_fd, const std::vector<std::string> &params)
{
	/*MODE CTan_ +i*/
	std::string target = params[1];
	if (_clients.find(client_fd) != _clients.end() &&
			_clients[client_fd].getNickname() == target)
	{
		if (params.size() < 3)
		{
			sendError(client_fd, "461", ":Not enough parameters for user modes");
			return;
		}
		std::string modeChanges = params[2];
		bool adding = true;
		for (size_t i = 0; i < modeChanges.size(); ++i)
		{
			switch (modeChanges[i])
			{
			case '+':
				adding = true;
				break;
			case '-':
				adding = false;
				break;
			default:
				_clients[client_fd].setMode(modeChanges[i], adding);
				break;
			}
		}
		SendBuffer = (":" + target + " MODE " + target + " :" + modeChanges + "\r\n");
		sendToClient(client_fd, SendBuffer);
	}
	else
	{
		sendError(client_fd, "502", "Cannot change mode for other users");
	}
}

void Server::channelMode(int client_fd, const std::vector<std::string> &params)
{
	std::string channelName = params[1];
	std::string modeSequence = (params.size() == 2) ? "" : params[2];
	if (modeSequence == "")
	{
		SendBuffer = (":localhost 324 " + channelName + " " + modeSequence + "\r\n");
		sendToClient(client_fd, SendBuffer);
		return;
	}
	std::string modeParam = (params.size() > 3) ? params[3] : "";

	std::vector<Channel>::iterator channelIt;
	for (channelIt = _channels.begin(); channelIt != _channels.end(); ++channelIt)
	{
		if (channelIt->getName() == channelName)
			break;
	}
	if (channelIt == _channels.end())
	{
		sendError(client_fd, "403", channelName + " :No such channel");
		return;
	}

	if (!(channelIt->isOperator(client_fd) || _clients[client_fd].isGlobalOp()))
	{
		sendError(client_fd, "482", channelName + " :You're not channel operator");
		return;
	}

	bool addingMode = (modeSequence[0] == '+');
	char mode = modeSequence[1];
	// std::cout << "size of params: " << params.size() << std::endl;
	switch (mode)
	{
	case 'i':
		if (modeSequence.size() == 2)
			channelIt->setInviteOnly(addingMode);
		else
		{
			sendError(client_fd, "461", channelName + " :No argument needed for /mode +i");
			return;
		}
		break;
	case 't':
		if (modeSequence.size() == 2) {
			if (!addingMode)
			{
				channelIt->removeTopicRestriction();
				break;	
			} else {
				channelIt->setTopicRestriction(addingMode);
				break;
			}
		} else {
			sendError(client_fd, "461", channelName + " :No argument needed for /mode +/-t");
			return;
		}
	case 'k':
		if (addingMode && (params.size() != 4 || modeSequence.size() != 2))
		{
			sendError(client_fd, "461", channelName + " :MODE synthax error /mode +k password");
			return;
		}
		if ((!addingMode && (params.size() != 4 || (params.size() == 4 && params[3] != "Mode"))) || modeSequence.size() != 2)
		{
			sendError(client_fd, "461", channelName + " :MODE synthax error /mode -k");
			return;
		}
		if (addingMode && modeParam.empty())
		{
			sendError(client_fd, "461", channelName + " :Password required to set +k");
			return;
		}
		if (addingMode) {
			channelIt->setPasswordRestriction(true);
			channelIt->setPassword(addingMode ? modeParam : "");
		} else {
			channelIt->setPasswordRestriction(false);
			channelIt->setPassword("");
		}
		break;
	case 'o':
	{
		if (params.size() < 4)
		{
			sendError(client_fd, "461", channelName + " :Parameter required for mode +/-o user");
			return;
		}
		if (!findnicknameIntoClient(params[3]))
		{
			sendError(client_fd, "442", params[1] + " :the client specified doesn't exit\r\n");
			return;
		}
		Client client = *findnicknameIntoClient(params[3]);
		if (addingMode)
			channelIt->addOperator(client.getFd());
		else
			channelIt->removeOperator(client.getFd());
		break;
	}
	case 'l':
		if (addingMode && modeParam.empty())
		{
			sendError(client_fd, "461", channelName + " :MODE Numeric parameter required for mode +l");
			return;
		}
		if (addingMode && (params.size() != 4 || modeSequence.size() != 2))
		{
			sendError(client_fd, "461", channelName + " :MODE synthax error /mode +l number");
			return;
		}
		if ((!addingMode && params.size() != 3) || (!addingMode && modeSequence.size() != 2))
		{
			sendError(client_fd, "461", channelName + " :MODE synthax error /mode -l");
			return;
		}
		if (!addingMode)
		{
			channelIt->removeUserLimit();
			break;
		}
		if (std::atoi(modeParam.c_str()) < 1 || std::atoi(modeParam.c_str()) < static_cast<int>(findChannelIntoServer(channelName)->getClientFds().size()) || std::atoi(modeParam.c_str()) > 100)
		{
			sendError(client_fd, "461", channelName + " :MODE Numeric parameter must be positive, lower than 100, higher than the actual client number");
			return;
		}
		channelIt->setUserLimit(addingMode ? std::atoi(modeParam.c_str()) : 0);
		break;
	default:
		std::string msg = ": 472 " + GetClient(client_fd).getNickname() + " " + channelName + " :is not a recognised channel mode" + "\r\n";
		send(client_fd, msg.c_str(), msg.length(), 0);
		return;
	}
	std::string response = ":" + _clients[client_fd].getNickname() + "!~" + _clients[client_fd].getUsername() + "@" + _clients[client_fd].getHostname() + " MODE " + channelName + " " + modeSequence + " :Mode set successfully\r\n";
	send(client_fd, response.c_str(), response.length(), 0);
}