/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:02 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:29:52 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal non identifie")
{
	std::cout << "Default constructor Animal called" << std::endl;
}

Animal::Animal(const Animal &a)
{
	*this = a;
}

Animal &Animal::operator=(const Animal &a)
{
	this->_type = a._type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << getType() << " says : Rrrrrrrr ! il va faire tout noir !!!" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->_type);
}

Animal::~Animal()
{
	std::cout << "Default destructor Animal called" << std::endl;
}