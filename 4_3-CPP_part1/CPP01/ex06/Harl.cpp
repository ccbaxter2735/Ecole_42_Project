/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:38:49 by terussar          #+#    #+#             */
/*   Updated: 2023/12/04 16:24:59 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "[DEBUG]"
						<< std::endl 
						<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
						<< std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO]"
						<< std::endl 
						<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
						<< std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]"
						<< std::endl
						<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
						<< std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]"
						<< std::endl
						<< "This is unacceptable ! I want to speak to the manager now."
						<< std::endl << std::endl;
}

int Harl::findLevel(std::string input)
{
	if (input == "DEBUG")
		return (1);
	else if (input == "INFO")
		return (2);
	else if (input == "WARNING")
		return (3);
	else if (input == "ERROR")
		return (4);
	else
		return (0);
}

void Harl::complain( int level )
{
	if (level == 0)
	{
		std::cout << "[NOTHING]"
						<< std::endl
						<< "Probably complaining about insignifient problems"
						<< std::endl << std::endl;
		return ;
	}
	if (level == 1)
		debug();
	if (level <= 2)
		info();
	if (level <= 3)
		warning();
	if (level <= 4)
		error();
}
