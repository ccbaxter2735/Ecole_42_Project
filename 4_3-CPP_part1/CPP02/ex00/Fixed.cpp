/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:01:21 by terussar          #+#    #+#             */
/*   Updated: 2023/12/16 21:38:25 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _nbVirg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_nbVirg = f.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &p)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(p.getRawBits());
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_nbVirg);
}

void Fixed::setRawBits( int const raw )
{
	_nbVirg = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
