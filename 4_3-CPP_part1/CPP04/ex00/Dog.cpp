/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:47 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:30:51 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Default constructor Dog called" << std::endl;
}

Dog::Dog(const Dog &a)
{
	this->_type = a._type;
}

void Dog::makeSound(void) const
{
	std::cout << getType() << " says : who let the dog out !!! houuf houfff houfff" << std::endl;
}

Dog &Dog::operator=(const Dog &a)
{
	this->_type = a._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Default destructor Dog called" << std::endl;
}