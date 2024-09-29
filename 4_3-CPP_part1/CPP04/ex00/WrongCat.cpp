/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:59:52 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:31:38 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Default constructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a)
{
	this->_type = a._type;
}

void WrongCat::makeSound(void) const
{
	std::cout << getType() << " says : houaf miaouh i don't remember who i'am" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &a)
{
	this->_type = a._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Default destructor WrongCat called" << std::endl;
}