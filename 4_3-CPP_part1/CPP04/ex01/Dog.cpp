/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:47 by terussar          #+#    #+#             */
/*   Updated: 2023/12/30 18:03:51 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(const Dog &a)
{
	this->_type = a._type;
	this->_brain = new Brain();
	*this = a;
	std::cout << "Copy constructor Dog called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << getType() << " says : who let the dog out !!! houuf houfff houfff" << std::endl;
}

Dog &Dog::operator=(const Dog &a)
{
	this->_type = a._type;
	for (int i = 0; i < 100; ++i)
		this->_brain->ideas[i] = a._brain->ideas[i];
	return *this;
}

std::string Dog::getBrain(void) const
{
	return(_brain->ideas[0]);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Default destructor Dog called" << std::endl;
}