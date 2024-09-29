/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:24:29 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 16:53:47 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default Constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Constructor ClapTrap called" << std::endl;
	_hitPoints = 10;
	_energy = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &p)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = p._name;
	_hitPoints = p._hitPoints;
	_energy = p._energy;
	_attackDamage = p._attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << " cannot attack he is dead !!!" << std::endl;
		return ;
	}
	if (this->_energy > 0)
	{
		std::cout << _name << " attacks " << target << " causing " << _attackDamage << " points of damage ! but has lost 1 energy" <<std::endl;
		this->_energy--;
	}
	else
		std::cout << _name << " has no more energy available !!!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << _name << " is attacked but he is already dead !!!" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << _name << " is attacked and he has lost " << amount << " hits points !!!" << std::endl;
	if (_hitPoints < 0)
	{
		std::cout << _name << " is dead" << std::endl;
		_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0)
	{
		this->_hitPoints += amount;
		std::cout << _name << " has gained " << amount << " hits points !!! but has lost 1 energy" << std::endl;
		this->_energy--;
	}
	else
		std::cout << _name << " has no more energy available !!!" << std::endl;
}

void ClapTrap::showStat()
{
	std::cout << std::endl
						<< "STAT" << std::endl
						<< _name << " --> energy : "
						<< _energy << " / health : "
						<< _hitPoints 
						<< std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &a)
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

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor ClapTrap of " << _name << " called" << std::endl;
}