/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:22:55 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 17:48:17 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// constructor
	ClapTrap ex1("tom");
	ClapTrap ex2("jerry");
	std::cout << std::endl;
	// constructor de recopie
	ClapTrap tom(ex1);
	ClapTrap jerry(ex2);
	std::cout << std::endl;
	
	// action
	jerry.showStat();
	tom.attack("jerry");
	jerry.takeDamage(5);
	jerry.showStat();
	std::cout << std::endl;
	
	jerry.beRepaired(10);
	jerry.showStat();
	
	tom.attack("jerry");
	jerry.takeDamage(50);
	jerry.showStat();
	jerry.takeDamage(5);
	jerry.beRepaired(10);
	jerry.showStat();
	std::cout << std::endl;
	return (0);
}
