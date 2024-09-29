/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:44 by terussar          #+#    #+#             */
/*   Updated: 2023/11/23 22:16:12 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

class Contact
{
private:
	// attributs
	std::string	firstName;
	std::string	lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

public:
	Contact(/* args */);
	~Contact();
	std::string	getValue(std::string prompt);
	std::string	reduceString(std::string info);
	void	initContact(void);
	void	printContact(int i);
};

#endif
