/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:05:21 by terussar          #+#    #+#             */
/*   Updated: 2024/03/29 13:47:43 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


# include <stack>
# include <deque>
# include <iostream>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:
		
	public:
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		MutantStack( void ) {};
		~MutantStack() {};

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};


#endif