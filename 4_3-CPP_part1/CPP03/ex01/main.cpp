/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:22:55 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 16:46:53 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// constructor
	ScavTrap ex1("tom");
	ScavTrap ex2("jerry");
	std::cout << std::endl;
	
	// constructor de recopie
	ScavTrap tom(ex1);
	ScavTrap jerry(ex2);
	std::cout << std::endl;
	
	// action
	tom.attack("jerry");
	jerry.takeDamage(120);
	jerry.showStat();
	tom.guardGate();
	tom.attack("jerry");
	tom.takeDamage(20);
	std::cout << std::endl;
	
	return (0);
}
