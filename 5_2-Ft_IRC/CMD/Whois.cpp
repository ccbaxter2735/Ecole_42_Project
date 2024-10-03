/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whois.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberard <vberard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:58:59 by vberard           #+#    #+#             */
/*   Updated: 2024/09/05 14:06:09 by vberard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server.hpp"

void Server::ircWHOIS(int client_fd, const std::vector<std::string> &params)
{
    if (params.size() < 2)
    {
        sendError(client_fd, "431", "WHOIS :Not enough parameters");
        return;
    }

    std::string targetNick = params[1];
    bool userFound = false;

    for (std::map<int, Client>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
        Client &client = it->second;
        if (client.getNickname() == targetNick)
        {
            userFound = true;
            std::ostringstream whoisReply;
            whoisReply << ":localhost 311 " << client.getNickname() << " " << client.getUsername()
                       << " ~" << client.getUsername() << " " << client.getHostname() << " * :" << client.getRealname() << "\r\n";
            send(client_fd, whoisReply.str().c_str(), whoisReply.str().length(), 0);

            std::ostringstream whoisServer;
            whoisServer << ":localhost 312 " << client.getNickname() << " " << client.getNickname() << " " << "localhost :Local IRC Server\r\n";
            send(client_fd, whoisServer.str().c_str(), whoisServer.str().length(), 0);

            std::ostringstream endOfWhois;
            endOfWhois << ":localhost 318 " << client.getNickname() << " " << client.getNickname() << " :End of WHOIS list.\r\n";
            send(client_fd, endOfWhois.str().c_str(), endOfWhois.str().length(), 0);
            break;
        }
    }

    if (!userFound)
    {
        sendError(client_fd, "401", targetNick + " :No such nick/channel");
    }
}
