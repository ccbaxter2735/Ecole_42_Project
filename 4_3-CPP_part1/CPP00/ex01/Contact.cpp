/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:32 by terussar          #+#    #+#             */
/*   Updated: 2023/11/23 18:10:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(/* args */)
{
	// firstName = "";
	// lastName = "";
	// nickname = "";
	// phoneNumber = "";
	// secret = "";
}

Contact::~Contact()
{
	firstName.erase();
	lastName.erase();
	nickname.erase();
	phoneNumber.erase();
	secret.erase();
}

std::string	Contact::getValue(std::string prompt)
{
	std::string	line;
	
	std::cout << prompt;
	while (line.empty())
	{
		std::cin >> line;
		if (std::cin.eof())
			exit(1);
	}
	return (line);
}

void	Contact::initContact(void)
{
	firstName = getValue("enter first name: ");
	lastName = getValue("enter last name: ");
	nickname = getValue("enter nickname: ");
	phoneNumber = getValue("enter phone number: ");
	secret = getValue("enter secret: ");
}

// MARK : reduce size of the information to put it into array
std::string Contact::reduceString(std::string info)
{
	if (info.length() > 10)
	{
		info[9] = '.';
		info.erase(10, info.length() - 10);
	}
	return (info);
}

void	Contact::printContact(int	i)
{
	if (i == 5)
	{
		std::cout << std::endl << "************** Contact's detail ************" << std::endl;
		std::cout << "* first name     : " << firstName << std::endl;
		std::cout << "* last name      : " << lastName << std::endl;
		std::cout << "* nickname       : " << nickname << std::endl;
		std::cout << "* phone number   : " << phoneNumber << std::endl;
		std::cout << "* darkest secret : " << secret << std::endl << std::endl;
	}
	else if (i == 0)
		std::cout << std::setw(10) << reduceString(firstName);
	else if (i == 1)
		std::cout << std::setw(10) << reduceString(lastName);
	else if (i == 2)
		std::cout << std::setw(10) << reduceString(nickname);
		
}
