/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:01:33 by terussar          #+#    #+#             */
/*   Updated: 2023/12/13 19:19:57 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
private:
	int _nbVirg;
	static const int _fract = 8;
public:
	Fixed();
	Fixed &operator=( const Fixed &);
	Fixed(const Fixed &p);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

