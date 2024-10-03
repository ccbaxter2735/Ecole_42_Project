/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:26 by terussar          #+#    #+#             */
/*   Updated: 2024/03/28 21:50:41 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <class T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;
public:
	Array( void );
	Array( unsigned int n );
	Array( const Array<T> &copy );
	Array<T> &operator=( const Array<T> &copy );
	T & 			operator[](unsigned int n) const;
	unsigned int	size(void) const;
	class InvalidIndex : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	~Array();
};

#include "Array.tpp"

#endif