/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:07 by terussar          #+#    #+#             */
/*   Updated: 2024/03/28 15:33:32 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void )
{
	std::cout << "Default Constructor called" << std::endl;
}

Span::Span( unsigned int N ): _N(N)
{
	std::cout << "Default initializer called" << std::endl;
}

Span::Span(Span const &copy) : _N(copy._N)
{
	this->_set.insert(copy._set.begin(), copy._set.end());
	std::cout << "Copy constructor called" << std::endl;
}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
	{
		this->_set.clear();
		this->_set.insert(copy._set.begin(), copy._set.end());
		this->_N = copy._N;
	}
	return (*this);
}


void Span::addNumber( int Nb )
{
	if (this->_set.size() < this->_N)
	{
		this->_set.insert(Nb);
		std::cout << "addNumber succesfully add " << Nb << " in the Span ! it size is now of " << this->_set.size() << std::endl;
	}
	else
		throw TooManyNumbersException();
}

void Span::addNumbers( int begin, int end )
{
	int addint[abs(begin - end) + 1];
	int small;
	
	if (this->_set.size() + (abs(begin - end) + 1) <= this->_N)
	{
		if ( begin > end ? small = end : small = begin)
		for (int i = 0; i < abs(begin - end) + 1; i++)
			addint[i] = small + i;
		this->_set.insert(addint, addint + (abs(begin - end) + 1));
	}
	else
		throw TooManyNumbersException();
}

void Span::showMember( void )
{
	std::cout << "list of Span members: ";
  for (std::set<int>::iterator it = this->_set.begin() ; it != this->_set.end(); ++it)
    std::cout << *it << ' ' ;
	std::cout << std::endl;
}

int Span::shortestSpan( void )
{
	int min;
	std::set<int>::iterator tmp;

	min = this->longestSpan();
	tmp = this->_set.begin();
	if (this->_set.size() > 1)
	{
		for (std::set<int>::iterator it = this->_set.begin(); it != this->_set.end(); ++it)
		{
			if ((*it - *tmp) < min && it != this->_set.begin())
				min = (*it - *tmp);
			tmp = it;
		}
		return (min);
	}
	else
		throw TooFewNumbersException();
}

int Span::longestSpan( void )
{
	if (this->_set.size() > 1)
		return (*(this->_set.rbegin()) - *this->_set.begin());
	else
		throw TooFewNumbersException();
}

Span::~Span()
{
	std::cout << "Default Destructor called" << std::endl;
}

const char* Span::TooManyNumbersException::what() const throw()
{
	return ("Error: Too many numbers in the span");
}

const char* Span::TooFewNumbersException::what() const throw()
{
	return ("Error: Too few numbers in the span");
}

const char* Span::WrongSpanSize::what() const throw()
{
	return ("Error: Wrong span size input");
}
