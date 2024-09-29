/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:02 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:29:52 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal non identifie")
{
	std::cout << "Default constructor AAnimal called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a)
{
	*this = a;
}

AAnimal &AAnimal::operator=(const AAnimal &a)
{
	this->_type = a._type;
	return *this;
}

void AAnimal::makeSound(void) const
{
	std::cout << getType() << " says : Rrrrrrrr ! il va faire tout noir !!!" << std::endl;
}

std::string AAnimal::getType( void ) const
{
	return (this->_type);
}

AAnimal::~AAnimal()
{
	std::cout << "Default destructor AAnimal called" << std::endl;
}