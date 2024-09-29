/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:37:26 by terussar          #+#    #+#             */
/*   Updated: 2023/12/22 20:11:37 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	std::string reponse;
	void (Harl::*ptr)(std::string) = &Harl::complain;
	Harl harl;
	
	while (1)
	{
		while (1)
		{
			std::cout << "Dans quel niveau de gravite Harl est il ? " << std::endl << std::endl;
			std::cout << "1 - DEBUG" << std::endl;
			std::cout << "2 - INFO" << std::endl;
			std::cout << "3 - WARNING" << std::endl;
			std::cout << "4 - ERROR" << std::endl << std::endl;
			std::cout << "Taper votre reponse : (DEBUG - INFO - ERROR - WARNING) ";
			std::cin >> reponse;
			if (std::cin.eof())
				return (1);
			// if (reponse >= "1" && reponse <= "4")
			break;
			// std::cerr << "Error : wrong input, try again !!! (1 - 4)" << std::endl << std::endl;
		}
		std::cout << "HARL shout : ";
		(harl.*ptr)(reponse);
		std::cout << std::endl;
		std::cout << "continuer ? (y/n) ";
		std::cin >> reponse;
		if (std::cin.eof())
			return (1);
		if (reponse == "n")
			break;
	}
	return (0);
}
