/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:01:10 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 17:17:28 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap()
{
	_hitPoints = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "Default Constructor FlagTrap called" << std::endl;
}

FlagTrap::FlagTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "Constructor FlagTrap " << _name << " called" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &p) : ClapTrap(p)
{
	std::cout << "Copy constructor FlagTrap called" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
	std::cout << "What's up guys ? hey HIGH FIVES !!! CLAP ((((@))))" << std::endl;
}

FlagTrap &FlagTrap::operator=(FlagTrap const &a)
{
	if (this != &a)
	{
		this->_name = a._name;
		this->_attackDamage = a._attackDamage;
		this->_energy = a._energy;
		this->_hitPoints = a._hitPoints;
	}
	return *this;
}

FlagTrap::~FlagTrap()
{
	std::cout << "Destructor FlagTrap called" << std::endl;
}
