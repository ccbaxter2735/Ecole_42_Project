/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:26:30 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 15:13:58 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel()
{
	// init all the private variable
	this->_name = "my_new_channel";
	this->_topic = "";
	this->_restrictTopic = false;
	this->_restrictInvite = false;
	this->_keyProtect = false;
	this->_password = "";
	this->_userLimit = 0;
	// std::cout << "Channel has been created successfully" << std::endl;
}

Channel::Channel(const std::string name, std::string topic)
{
	this->_name = name;
	this->_topic = topic;
	this->_restrictTopic = false;
	this->_restrictInvite = false;
	this->_keyProtect = false;
	this->_password = "";
	this->_userLimit = 0;
	// std::cout << "Channel has been changed successfully" << std::endl;
}

void Channel::setName(std::string name)
{
	this->_name = name;
	// std::cout << "Channel's has been changed for: << " + name + " >> successfully" << std::endl;
}

void Channel::setKey(std::string key)
{
	if (this->_keyProtect == false) {
		this->_keyProtect = true;
		this->_key = key;
		// std::cout << this->getName() + " is now a key protected channel\n";
	}
	else {
		this->_keyProtect = false;
		// std::cout << this->getName() + " is now a non-protected channel\n";
	}
}
void Channel::setInviteOnly(bool status) { _restrictInvite = status; }
void Channel::setTopicRestriction(bool status) { _restrictTopic = status; }
void Channel::setPassword(const std::string& password) { _password = password; }
void Channel::setPasswordRestriction(bool status) { _keyProtect = status; }
void Channel::setUserLimit(int limit) { _userLimit = limit; }

std::string Channel::getName(void) const { return (this->_name); }
std::string Channel::getTopic(void) const { return (this->_topic); }
std::vector<int> Channel::getClientFds( void ) const { return _clientFds; }
bool Channel::getKeyProtect( void ) { return (this->_keyProtect); }
std::string Channel::getKey( void ) { return (this->_key);}
bool Channel::getInviteOnly() const { return _restrictInvite; }
bool Channel::getTopicRestriction() const { return _restrictTopic; }
std::string Channel::getPassword() const { return _password; }
int Channel::getUserLimit() const { return _userLimit; }
bool Channel::getRestrictTopic(void){ return (this->_restrictTopic); }
bool Channel::getRestrictInvite(void){ return (this->_restrictInvite); }

void Channel::addOperator(int clientFd) { _operators.insert(clientFd); }
void Channel::removeOperator(int clientFd) { _operators.erase(clientFd); }
bool Channel::isOperator(int clientFd) const { return _operators.find(clientFd) != _operators.end(); }
std::string Channel::GetTime(){return this->_timeCreation;}

bool Channel::isInvited(int clientFd) { return _invitedClients.find(clientFd) != _invitedClients.end(); }
void Channel::addInvite(int clientFd) { _invitedClients.insert(clientFd); }

void Channel::removeUserLimit() { _userLimit = 0; }
void Channel::removeTopicRestriction() {_restrictTopic = 0;}




// TOPIC command
void Channel::setTopic(std::string topic)
{
	if (topic != this->_topic) {
		this->_topic = topic;
	}
}

void Channel::setTime(std::string time) {
	this->_timeCreation = time;
}

void Channel::addClient(int clientFd) {
    if (std::find(_clientFds.begin(), _clientFds.end(), clientFd) == _clientFds.end()) {
         _clientFds.push_back(clientFd);
    }
}

void Channel::removeClient(int clientFd) {
    std::vector<int>::iterator it = std::find(_clientFds.begin(), _clientFds.end(), clientFd);
    if (it != _clientFds.end()) {
        _clientFds.erase(it);
    }
}

void Channel::removeInvite(int clienFd){
	if (_invitedClients.find(clienFd) != _invitedClients.end())
		_invitedClients.erase(clienFd);
}

// check if a nickname is inside a channel
bool Channel::findnicknameIntoChannel(int client_fd) {
	if (std::find(_clientFds.begin(), _clientFds.end(), client_fd) != _clientFds.end())
		return true;
	return false;
}

/*Channel boardcast*/
void Channel::ChannelBroadcast(const std::string& message) {
    std::vector<int>::iterator it;
    for (it = _clientFds.begin(); it != _clientFds.end(); ++it) {
            send(*it, message.c_str(), message.length(), 0);
    }
}

Channel::~Channel()
{
	// std::cout << "Channel has been destroyed successfully" << std::endl;
}
