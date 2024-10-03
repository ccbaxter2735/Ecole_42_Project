/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:56:12 by terussar          #+#    #+#             */
/*   Updated: 2024/08/06 14:14:52 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Server.hpp"

class Channel;
class Server;

class Client {
private:
    int fd;
    std::string username;
    std::string nickname;
    std::string realname;
    std::string hostname;
    std::string servername;
    bool _globalOp;
    bool authed;
    bool _canInvite;
    
    std::set<std::string> channelOps;
    std::string currentChannel;
    std::string ipadd;
    std::vector<std::string> ChannelsInvite;
    std::map<char, bool> userModes;

public:
    Client();
    Client(int fd);
    ~Client();
    int getFd() const;
    std::string getUsername() const;
    std::string getNickname() const;
    std::string getRealname() const;
    std::string getHostname() const;
    std::string getServername() const;
    bool isGlobalOp() const;
    bool isAuthed() const;

    void setGlobalOp(bool status);
    void setNickname(const std::string& nname);
    void setUsername(const std::string& uname);
    void setRealName(const std::string& name);
    void setHostname(const std::string& host);
    void setServername(const std::string& server);
    void setAuthed(const bool& auth);
    void setInvite(bool status);

    void addChannelOp(const std::string& channel);
    void removeChannelOp(const std::string& channel);
    bool isChannelOp(const std::string& channel) const;
    
    void setCurrentChannel(const std::string& channelName);
    std::string getCurrentChannel() const;
    void AddChannelInvite(std::string &channelName);

    void setMode(char mode, bool enabled);
    bool getMode(char mode) const;
};