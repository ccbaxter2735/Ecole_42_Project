/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:18 by terussar          #+#    #+#             */
/*   Updated: 2023/11/23 18:07:17 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
	index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(int flag)
{
	if (flag > 7)
		contacts[index].~Contact();
	std::cout << std::endl << "******* New Contact editor *******" << std::endl;
	std::cout << std::endl << "-- INDEX #" << index << " --" << std::endl;
	contacts[index].initContact();
	std::cout << std::endl << "*********** end editor ***********" << std::endl;
	std::cout << std::endl;
	index++;
	index = index % 8;
}

void	PhoneBook::printTab(int flag)
{
	int nb = 10;
	int max;
	
	if (flag <= index)
		max = index;
	else
		max = 8;
	std::cout << std::endl << "**************** PhoneBook ******************" << std::endl;
	std::cout << "|  index   |first name| last name| nickname |" << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < max; i++)
	{
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|';
		contacts[i].printContact(0);
		std::cout << '|';
		contacts[i].printContact(1);
		std::cout << '|';
		contacts[i].printContact(2);
		std::cout << '|' << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
	while (1)
	{
		std::cout << std::endl << "enter contact's index you're looking for : " ;
		std::cin >> nb;
		if (std::cin.eof())
			return ;
		if (nb < max && nb >= 0)
			break;
		std::cout << "wrong input index empty try again !" << " (0 - " << (max - 1) << ")";
	}
	contacts[nb].printContact(5);
}
