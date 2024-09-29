/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:38:44 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:31:15 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "Default constructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
	this->_type = a._type;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << getType() << " says : wrongAnimal sound ! Creepy" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	this->_type = a._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Default destructor WrongAnimal called" << std::endl;
}