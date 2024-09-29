/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:37:26 by terussar          #+#    #+#             */
/*   Updated: 2023/12/04 16:21:49 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char const *av[])
{
	int (Harl::*ptr1)(std::string) = &Harl::findLevel;
	void (Harl::*ptr2)(int) = &Harl::complain;
	Harl harl;
	
	if (ac == 2)
	{
		int result = (harl.*ptr1)(av[1]);
		(harl.*ptr2)(result);
	}
	return (0);
}
