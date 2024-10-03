/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:30:04 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 13:37:08 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

bool RPN::evaluateNPI(std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	int nombre;

	while (iss >> token) 
	{
		// Si le token est un nombre, le convertir en int et le pousser sur la pile
		if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1])))
		{	
			nombre = static_cast<int>(strtod(token.c_str(), NULL));
			// if (nombre < -9 || nombre > 9)
			// 	return (false);
			this->pile.push(nombre);
		} 
		else 
		{ // Sinon, le token est un opérateur
			if (this->pile.size() < 2)
				return (false);
			int op2 = this->pile.top();
			pile.pop();
			int op1 = this->pile.top();
			pile.pop();

			// Effectuer l'opération correspondante et pousser le résultat sur la pile
			if (token == "+")
				this->pile.push(op1 + op2);
			else if (token == "-")
				this->pile.push(op1 - op2);
			else if (token == "*")
				this->pile.push(op1 * op2);
			else if (token == "/")
			{
				if (op2 == 0)
					return (false);
				this->pile.push(op1 / op2);
			}
		}
	}
	if (this->pile.size() == 1)
	{
		this->result = this->pile.top();
		return (true);
	}
	return (false);
}

int RPN::getResult( void )
{
	return (this->result);
}

RPN &RPN::operator=(const RPN &copy)
{
	if (this != &copy)
	{
		while (this->pile.size() > 0)
			this->pile.pop();
		this->pile = copy.pile;
	}
	return (*this);
}

RPN::~RPN()
{
}