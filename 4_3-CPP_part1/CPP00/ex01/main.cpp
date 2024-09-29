/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:56:49 by terussar          #+#    #+#             */
/*   Updated: 2023/11/24 11:12:33 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook rep;
	int	first;
	
	first = 0;
	std::cout << "***** you enter into awesome phonebook *****" << std::endl << std::endl;
	while (1)
	{
		while (1)
		{
			std::cout << "enter command (ADD / SEARCH / EXIT) : ";
			std::cin >> cmd;
			if (std::cin.eof())
				return (1);
			if (cmd == "ADD" || cmd == "EXIT" || cmd == "SEARCH")
				break ;
			std::cerr << "error : wrong input ! start again ..." << std::endl;
		}
		if (cmd == "ADD")
		{
			rep.addContact(first);
			first++;
		}
		else if (cmd == "SEARCH")
		{
			if (first)
				rep.printTab(first);
			else
				std::cerr << "there is no contact in the book, add a contact before looking for one" << std::endl;
		}
		else
			break ;
	}
	std::cout << std::endl << "******** you leave awesome phonebook *******";
	return (0);
}
