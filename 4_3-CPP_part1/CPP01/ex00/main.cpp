/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:16:41 by terussar          #+#    #+#             */
/*   Updated: 2023/12/16 19:25:28 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string	name1;
	std::string	name2;
	
	std::cout << "create zombie in the stack" << std::endl;
	std::cout << "what's zombie's name ? ";
	std::cin >> name1;
	if (std::cin.eof())
		return (1);
	
	std::cout << std::endl;
	Zombie zomb1(name1);
	zomb1.announce();
	std::cout << std::endl;
	
	std::cout << "create zombie in the heap" << std::endl;
	std::cout << "what's zombie's name ? ";
	std::cin >> name2;
	if (std::cin.eof())
		return (1);
	
	std::cout << std::endl;
	Zombie *zomb2 = newZombie(name2);
	zomb2->announce();
	delete zomb2;
	std::cout << std::endl;

	std::cout << "create zombie in the stack with non-member function" << std::endl;
	randomChump( "bob" );

	return (0);
}
