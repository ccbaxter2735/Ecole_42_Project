/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:51:44 by terussar          #+#    #+#             */
/*   Updated: 2024/02/22 15:50:55 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string str(av[1]);
		ScalarConverter::convert(str);
	}
	else
	{
		std::cerr << "error: one argument required" << std::endl;
		return (1);
	}
	return (0);
}
