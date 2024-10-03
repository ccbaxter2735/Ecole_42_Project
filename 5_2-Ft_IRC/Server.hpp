/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:09:26 by terussar          #+#    #+#             */
/*   Updated: 2024/09/08 19:54:54 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <cstring>
#include <csignal>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <set>
#include <algorithm>
#include <cerrno>
#include <cmath>
#include <cstdio>
#include "Channel.hpp"
#include "Client.hpp"
#include "serverMsg.hpp"

#define MAX_EVENTS 10
#define BUFFER_SIZE 1024

extern volatile std::sig_atomic_t g_terminate;

class Channel;
class Client;

class Server {
private:
    int server_fd, epoll_fd;
    std::map<int, std::string> client_buffers;
    std::vector<Channel> _channels;
    std::map<int, Client> _clients;

    std::string password;
    const std::string oper_password;
    std::string SendBuffer;
    time_t RawTime;
    struct tm *TimeInfo;

    int set_non_blocking(int fd);

    void setupSocketOptions(int sockfd);

    void broadcast(const std::string& message, int sender_fd);


		Client GetClient(int fd);
		
		Client *findnicknameIntoClient(std::string nickname);
		Channel *findChannelIntoServer(std::string channelName);
		int *findClientFdIntoServer(std::string nickname);
		void listChaine( void );
		void addChannel(Channel channel);
		void addClient(Client client);

		bool findValueInVector(const std::vector<int>& vec, int value);
		
		std::string Invite(std::string channelName, std::string nickname, Client client);
		void Topic(std::string channelName, std::string message, int client_fd);
		std::string Kick(std::string channelName, std::string nickname, std::string message, Client client);
		std::string Mode(std::vector<std::string> mode);
		std::vector<std::string> _splitCommand(std::string &command);
		std::vector<std::string> parseCommand(std::string &command);
		void checkMode(std::string mode, int length);
		void executeMode(Channel channel, std::string modeSelected, int i, std::string arg, int client_fd);
		void executeAllMode(Channel channel, std::vector<std::string> mode, int client_fd);
		
		void sendErrC(int code, std::string clientname, std::string channelname, int fd, std::string msg);
		void sendError(int client_fd, const std::string& code, const std::string& message);
		void sendErr(int code, std::string clientname, int fd, std::string msg);
		void sendMsg(std::string response, int fd);
		std::string timeTopic();

    bool isValidCommand(const std::string &command);
    void processInvalidCommand(int client_fd, const std::string &command);

    void ircNICK(int client_fd, const std::vector<std::string> &params);
    void ircJOIN(int client_fd, const std::vector<std::string> &params);
    void ircUSER(int client_fd, const std::vector<std::string> &params);
    void ircPASS(int client_fd, const std::vector<std::string> &params);
    void ircPONG(int client_fd, const std::vector<std::string> &params);
    void ircPART(int client_fd, const std::vector<std::string> &params);
    void ircQUIT(int client_fd, const std::vector<std::string> &params);
	void ircTOPIC(int client_fd, const std::vector<std::string>& params);
	void ircINVITE(int client_fd, const std::vector<std::string>& params);
	void ircKICK(int client_fd, const std::vector<std::string>& params);
	void ircMODE(int client_fd, const std::vector<std::string>& params);
		void channelMode(int client_fd, const std::vector<std::string> &params);
		void userMode(int client_fd, const std::vector<std::string> &params);
	void ircOPER(int client_fd, const std::vector<std::string> &params);
	void ircPRIVMSG(int client_fd, const std::vector<std::string> &params);
	void ircWHO(int client_fd, const std::vector<std::string> &params);
	void ircWHOIS(int client_fd, const std::vector<std::string> &params);
    
	void processCommand(int client_fd, const std::vector<std::string> &cmdVector);

public:
    ~Server();
    Server(int port, const std::string &pass);
		void run();
		void printParams(const std::vector<std::string> &a) const;
		void sendToClient(int client_fd, std::string msg);
		void printClientStatus(int client_fd) const;

		// exception ///////////////
		class InviteAccessLevel 	:	public std::exception { public: virtual const char* what() const throw(); };
		class KickAccessLevel			:	public std::exception { public: virtual const char* what() const throw(); };
		class ChannelUnavailable	: public std::exception { public: virtual const char* what() const throw(); };
		class NotavailableChannel : public std::exception { public: virtual const char* what() const throw(); };
		class NotavailableUser		: public std::exception { public: virtual const char* what() const throw(); };
		class AlreadyIntoChannel	: public std::exception { public: virtual const char* what() const throw(); };
		class TopicAccessLevel		: public std::exception { public: virtual const char* what() const throw(); };
		class SizeOverride				: public std::exception { public: virtual const char* what() const throw(); };
		class unavailableMode			: public std::exception { public: virtual const char* what() const throw(); };
		class nbArgumentMistake		: public std::exception { public: virtual const char* what() const throw(); };
		class nbArgumentMistakeTopic : public std::exception { public: virtual const char* what() const throw(); };
		class nbArgumentMistakeInvite : public std::exception { public: virtual const char* what() const throw(); };
		class nbArgumentMistakeKick : public std::exception { public: virtual const char* what() const throw(); };	
		class unavailableKick	{
			private:
				std::string channelName;
				std::string errMsg;
			public:
				unavailableKick(const std::string& channel) : channelName(channel) {
					errMsg = "ERROR: clients cannot be kicked outside " + channelName;
				}
				virtual ~unavailableKick() throw() {}  // Ajout du destructeur virtuel
				virtual const char* what() const throw() {
						return errMsg.c_str();
				}
		};
};
void	signal_handler(int signal);