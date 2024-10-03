/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:35:07 by terussar          #+#    #+#             */
/*   Updated: 2024/09/05 16:07:03 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client() : fd(-1), username(""), nickname(""), realname(""), hostname(""), servername(""), _globalOp(false), authed(false), _canInvite(false) {}
Client::Client(int fd)
        : fd(fd), username(""), nickname(""), realname(""), hostname(""), servername(""), _globalOp(false), authed(false), _canInvite(false) {}
Client::~Client(){}

int Client::getFd() const { return fd; }
std::string Client::getUsername() const { return username; }
std::string Client::getNickname() const { return nickname; }
std::string Client::getRealname() const { return realname; }
std::string Client::getHostname() const { return hostname; }
std::string Client::getServername() const { return servername; }
bool Client::isGlobalOp() const { return _globalOp; }
bool Client::isAuthed() const { return authed; }

void Client::setGlobalOp(bool status) { _globalOp = status; }
void Client::setNickname(const std::string& nname) { nickname = nname; }
void Client::setUsername(const std::string& uname) { username = uname; }
void Client::setRealName(const std::string& name) { realname = name; }
void Client::setHostname(const std::string& host) { hostname = host; }
void Client::setServername(const std::string& server) { servername = server; }
void Client::setAuthed(const bool& auth) { authed = auth; }
void Client::setInvite(bool status) { _canInvite = status; }

void Client::addChannelOp(const std::string& channel) { channelOps.insert(channel); }
void Client::removeChannelOp(const std::string& channel) { channelOps.erase(channel); }
bool Client::isChannelOp(const std::string& channel) const { return channelOps.find(channel) != channelOps.end(); }

void Client::setCurrentChannel(const std::string& channelName) { currentChannel = channelName; }
std::string Client::getCurrentChannel() const { return currentChannel; }
void Client::AddChannelInvite(std::string &channelName){ ChannelsInvite.push_back(channelName); }
void Client::setMode(char mode, bool enabled) { userModes[mode] = enabled; }