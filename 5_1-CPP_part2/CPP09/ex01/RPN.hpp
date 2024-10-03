/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:30:13 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 16:48:26 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <list>
#include <cstdlib>

typedef std::stack<int, std::list<int> > stack;

class RPN
{
private:
	stack pile;
	int result;
public:
	RPN();
	RPN(const RPN &copy);
	bool evaluateNPI(std::string& expression);
	int getResult( void );
	RPN &operator=(const RPN &copy);
	~RPN();
};


#endif