/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:01:21 by terussar          #+#    #+#             */
/*   Updated: 2023/12/22 22:13:35 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fract = 8;

Fixed::Fixed(void) : _nbVirg(0)
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(int const point) : _nbVirg(point << Fixed::_fract)
{
	std::cout << "Int constructor called" << std::endl;

	return;
}

Fixed::Fixed(float const point) : _nbVirg(roundf(point * (1 << Fixed::_fract)))
{
	std::cout << "Float constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

Fixed &Fixed::operator=(Fixed const &a)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	if (this != &a)
		this->_nbVirg = a._nbVirg;

	return *this;
}

// ---------------------- Member function -------------------------

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->_nbVirg;
}

void Fixed::setRawBits(int const raw)
{
	this->_nbVirg = raw;
}

float Fixed::toFloat(void) const
{
	return this->_nbVirg / static_cast<float>(1 << Fixed::_fract);
}

int Fixed::toInt(void) const
{
	return _nbVirg >> Fixed::_fract;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();

	return o;
}