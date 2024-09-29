/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:38 by terussar          #+#    #+#             */
/*   Updated: 2023/12/30 17:36:28 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Default constructor Cat called" << std::endl;
}

Cat::Cat(const Cat &a)
{
	this->_type = a._type;
	this->_brain = new Brain();
	*this = a;
}

void Cat::makeSound(void) const
{
	std::cout << getType() << " says : meaaaaaaaouhhhhhhhh !!!" << std::endl;
}

Cat &Cat::operator=(const Cat &a)
{
	this->_type = a._type;
	for (int i = 0; i < 100; ++i)
		this->_brain->ideas[i] = a._brain->ideas[i];
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Default destructor Cat called" << std::endl;
}