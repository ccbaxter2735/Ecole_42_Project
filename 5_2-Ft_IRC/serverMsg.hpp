#pragma once
#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"

/*Welcome*/
# define RPL_001(nick, username) (":localhost 001 " + nick + " :Welcome to the \033[1;5;33mEpic IRC\033[0m! " + nick + "~" + username + "@localhost\r\n")
# define RPL_002(nick, host, version) (":localhost 002 " + nick + " :Your host is " + host + " (localhost), running version " + version + "\r\n")
# define RPL_003(nick, datetime) (":localhost 003 " + nick + " :This server was created " + datetime + "\r\n")
# define RPL_004(nick, host, version, user_modes, chan_modes, chan_param_modes) (":localhost 004 " + nick + " " + host + " " + user_modes + chan_modes + chan_param_modes + "\r\n")
# define RPL_005(nick, tokens) (":localhost 005 " + nick + " " + tokens " :are available on this server\r\n")

/*NICK*/
# define ERR_ERRONEUSNICKNAME(nick, bname) (":localhost 432 " + nick + " " + bname + " :Erroneous Nickname\r\n")
# define ERR_NICKNAMEINUSE(nick) (":localhost 433 NICK :" + nick + " is already in used\r\n")
# define RPL_NICK(onick, uname, nnick) (":" + onick + "!" + uname + "@localhost NICK :" + nnick + "\r\n")

/*PONG*/
# define RPL_PONG(host, nick) ("PONG " + host + + " :" + nick + "\r\n")

/*OPER*/
# define RPL_OPER(nick) (":localhost 381 " + nick + " :\033[1;1;32mYou are now an IRC operator\033[0m\r\n")
# define ERR_491(nick) (":localhost 491 " + nick + " You're already a server operator\r\n")
# define ERR_464(nick) (":localhost 464 " + nick + " :\033[1;1;31mPassword incorrect\033[0m\r\n")

/*PART*/
# define RPL_PART(nick, uname, channel, reason) (":" + nick + "!" + uname + "@localhost PART " + channel  + " " + reason + "\r\n")
# define ERR_NOSUCHCHANNEL(nick, channel) (":localhost 403 " + nick + " " + channel + " :No such channel\r\n")
# define ERR_NOTONCHANNEL(nick, channel) (":localhost 442 " + nick + " " + channel + " :You're not on that channel\r\n")

/*QUIT*/
# define RPL_QUIT(reason) ("QUIT " + reason + "\r\n")

# define ERR_421(nick, command) (":localhost 421 " + nick + " " + command + " :Unknown command\r\n")