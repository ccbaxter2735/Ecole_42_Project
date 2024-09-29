/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:38 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:30:13 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Default constructor Cat called" << std::endl;
}

Cat::Cat(const Cat &a)
{
	this->_type = a._type;
}

void Cat::makeSound(void) const
{
	std::cout << getType() << " says : meaaaaaaaouhhhhhhhh !!!" << std::endl;
}

Cat &Cat::operator=(const Cat &a)
{
	this->_type = a._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Default destructor Cat called" << std::endl;
}