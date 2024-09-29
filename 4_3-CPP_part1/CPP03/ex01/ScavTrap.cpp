/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:43:55 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 17:14:39 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energy = 50;
	_attackDamage = 20;
	_gate = false;
	std::cout << "Default Constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energy = 50;
	_attackDamage = 20;
	_gate = false;
	std::cout << "Constructor ScavTrap " << _name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &p) : ClapTrap(p)
{
	_gate = p._gate;
	std::cout << "Copy constructor ScavTrap called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energy > 0 && _hitPoints > 0 && _gate == false)
	{
		std::cout << _name << " attacks " << target << " and cause " << _attackDamage << " points of damage. " << _name << " lost 1 pt of energy" << std::endl;
		_energy--;
	}
	if (_energy == 0)
		std::cout << _name << " has no more energy to attack someone !!!" << std::endl;
	if (_hitPoints == 0)
		std::cout << _name << " has no more health to attack someone !!!" << std::endl;
	if (_gate == true)
		std::cout << _name << " is in Gate keeper mode and cannot attack someone !!!" << std::endl;
	
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_gate == true)
	{
		std::cout << _name << " is attacked but he is in gate keeper mode !!!" << std::endl;
		return ;
	}
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

void ScavTrap::guardGate( void )
{
	if (_gate == false)
	{
		_gate = true;
		std::cout << _name << " is now in Gate keeper mode" << std::endl;
	}
	else
	{
		_gate = false;
		std::cout << _name << " is NO MORE in Gate keeper mode" << std::endl;
	}
}

ScavTrap &ScavTrap::operator=(ScavTrap const &a)
{
	if (this != &a)
	{
		this->_name = a._name;
		this->_attackDamage = a._attackDamage;
		this->_energy = a._energy;
		this->_hitPoints = a._hitPoints;
		this->_gate = a._gate;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}