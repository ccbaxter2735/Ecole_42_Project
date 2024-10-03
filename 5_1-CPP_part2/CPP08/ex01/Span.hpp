/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:12 by terussar          #+#    #+#             */
/*   Updated: 2024/03/28 15:27:52 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>

class Span
{
private:
	unsigned int		_N;
	std::multiset<int> 	_set;
public:
	Span(void);
	Span(unsigned int _N);
	Span(Span const &copy);
	Span &operator=(Span const &copy);
	void addNumber( int Nb );
	void addNumbers( int begin, int end );
	int shortestSpan( void );
	int longestSpan( void );
	void showMember( void );
	~Span();
	class TooManyNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class TooFewNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class WrongSpanSize : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif

