/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:01:21 by terussar          #+#    #+#             */
/*   Updated: 2023/12/22 18:49:11 by terussar         ###   ########.fr       */
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
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return;
}

// ---------------------- OPERATOR -------------------------

Fixed &Fixed::operator=(Fixed const &a)
{
	// std::cout << "Copy assignment operator called" << std::endl;

	if (this != &a)
		this->_nbVirg = a._nbVirg;

	return *this;
}

bool Fixed::operator>( const Fixed &a)
{
	return this->_nbVirg > a._nbVirg;	
}

bool Fixed::operator<( const Fixed &a)
{
	return _nbVirg < a._nbVirg;
}

bool Fixed::operator>=( const Fixed &a)
{
	return _nbVirg >= a._nbVirg;
}

bool Fixed::operator<=( const Fixed &a)
{
	return _nbVirg <= a._nbVirg;
}

bool Fixed::operator==( const Fixed &a)
{
	return _nbVirg == a._nbVirg;
}

bool Fixed::operator!=( const Fixed &a)
{
	return _nbVirg != a._nbVirg;
}

// ---------------------- Member function -------------------------

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

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

// ---------------- increase / decrease function -----------

Fixed&  Fixed::operator++(void)
{
	_nbVirg++;
	return *this;
}

Fixed   Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed&  Fixed::operator--(void)
{
	_nbVirg--;
	return *this;
}

Fixed   Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}
// --------------------- math operator ---------------------

Fixed   Fixed::operator+(const Fixed &a) const
{
    return (Fixed(toFloat() + a.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &a) const
{
    return (Fixed(toFloat() - a.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &a) const
{
    return (Fixed(toFloat() * a.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &a) const
{
    return (Fixed(toFloat() / a.toFloat()));
}

// --------------------- min / max functions ---------------

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed &min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
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