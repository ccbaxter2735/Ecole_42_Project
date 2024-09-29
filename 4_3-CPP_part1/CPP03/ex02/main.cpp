/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:22:55 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 17:42:06 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FlagTrap.hpp"

int main(void)
{
	// constructor
	FlagTrap ex1("tom");
	FlagTrap ex2("jerry");
	std::cout << std::endl;
	
	// constructor de recopie
	FlagTrap tom(ex1);
	FlagTrap jerry(ex2);
	std::cout << std::endl;
	
	// action
	tom.attack("jerry");
	jerry.takeDamage(120);
	jerry.showStat();
	tom.attack("jerry");
	jerry.takeDamage(120);
	tom.showStat();
	tom.highFivesGuys();
	tom.takeDamage(20);
	std::cout << std::endl;
	
	return (0);
}
