/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:52:25 by terussar          #+#    #+#             */
/*   Updated: 2024/04/03 18:44:27 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool checkExpression(std::string exp)
{
	std::istringstream iss(exp);
	std::string token;

  while (iss >> token)
	{
		std::size_t i = -1;
		while (++i < token.size())
		{
			if (!isdigit(token[i]))
			{
				if (token[i] != '+' && token[i] != '*' && token[i] != '/' && token[i] != '-' && token[i] != ' ')
					return (false);
			}
		}
		if (!isdigit(token[0]) && token[0] != '-' && token[0] != '+' && token[0] != '*' && token[0] != '/')
			return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	RPN rpn;
	
	if (ac == 2)
	{
    std::string expression = av[1];

		if (!checkExpression(av[1]))
		{
			std::cerr << "Error: contain token which is not operator or number" << std::endl;
			return (1);
		}
    if (rpn.evaluateNPI(expression) == true)
    	std::cout << "Résultat: " << rpn.getResult() << std::endl;
		else
		{
			std::cerr << "Error: expression is not valid" << std::endl;
			return (1);
		}
	}
	else
	{
		std::cerr << "Error: two arguments needed" << std::endl;
		return (1);
	}
  return 0;
}