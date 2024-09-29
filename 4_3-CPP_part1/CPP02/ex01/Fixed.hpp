/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:01:33 by terussar          #+#    #+#             */
/*   Updated: 2023/12/22 19:28:31 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
	int _nbVirg;
	static const int _fract;
public:
	Fixed();
	Fixed( Fixed const &src );
	Fixed( int const point );
	Fixed( float const point );
	
	Fixed &operator=( const Fixed &a );
	
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	
	Fixed const& min(const Fixed &a, const Fixed &b);
	Fixed const& max(const Fixed &a, const Fixed &b);
	Fixed &min(Fixed &a, Fixed &b);
	Fixed &max(Fixed &a, Fixed &b);
	
	~Fixed();
};
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif