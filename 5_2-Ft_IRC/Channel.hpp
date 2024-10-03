/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:26:43 by terussar          #+#    #+#             */
/*   Updated: 2024/09/09 14:35:42 by jo-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "Server.hpp"

class Client;
// std::string name - nickname du client
// Bool superuser - boolean pour voir si superuser ou pas
// Bool _operator - bool pour indiquer si operator ou user

class Server;
// vector _channels - list des channels du serveur
// vector _clients - list des clients du serveur

class Channel
{
private:
	std::string _name;
	std::string _topic;
	std::string _key;
	std::string _timeCreation;

	std::vector<int> _clientFds;
	std::set<int> _operators;
	
	bool _restrictTopic; //false by default
	bool _restrictInvite; //false by default
	bool _keyProtect; //false by default
	
	std::string _password;
	std::set<int> _invitedClients;
	int	_userLimit;
	
public:
	// constructors ///////////////
	Channel();
	Channel(const std::string name, std::string topic);
	// setters ////////////////////
	void setName(std::string name);
	void setTopic(std::string topic);
	void setKey(std::string key);
	void setInviteOnly(bool status);
	void setTopicRestriction(bool status);
	void setPassword(const std::string& password);
	void setPasswordRestriction(bool status);
	void setUserLimit(int limit);
	// getters ////////////////////
	std::string getName( void ) const;
	std::string getTopic( void ) const;
	std::vector<int> getClientFds( void ) const;
	bool getRestrictTopic( void );
	bool getRestrictInvite( void );
	bool getKeyProtect( void );
	std::string getKey( void );
	bool getInviteOnly() const;
	bool getTopicRestriction() const;
	std::string getPassword() const;
	int getUserLimit() const;
	std::string GetTime();
	
	void addOperator(int clientFd);
    void removeOperator(int clientFd);
    bool isOperator(int clientFd) const;
    
    void removeUserLimit(void);
	void removeTopicRestriction(void);
	
	// functions for CMD //////////
	bool findnicknameIntoChannel(int client_fd);
	void kickClient(std::string name);
	void addClient(int clientFd);
    void removeClient(int clientFd);

	void sendAllFd(std::string msg);
	void setTime(std::string time);

	void ChannelBroadcast(const std::string& message);
	bool isInvited(int clientFd);
	void addInvite(int clientFd);
	void removeInvite(int clienFd);

	// destructor /////////////////
	~Channel();
};


// les commandes doivent etre faite en dehors de la class Channel car peut concerner n'imp quelle channel
// return string

// KICK - Ejecter un client du channel - /kick <#channel> <nickname> [raison] -->
// INVITE - Inviter un client au channel - /invite <nickname> -->
// TOPIC - Modifier ou afficher le thème du channel - /topic <#channel> <message> --> setTopic 
// MODE - Changer le mode du channel : - /mode #channel +/-[mode] -->
// — i : Définir/supprimer le canal sur invitation uniquement
// — t : Définir/supprimer les restrictions de la commande TOPIC pour les opérateurs de canaux
// — k : Définir/supprimer la clé du canal (mot de passe) - k <clé> -->
// — o : Donner/retirer le privilège de l’opérateur de canal - 
// — l : Définir/supprimer la limite d’utilisateurs pour le canal - l <nombre maximum d'utilisateurs>

#endif