/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:38:49 by terussar          #+#    #+#             */
/*   Updated: 2023/12/22 20:10:09 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string const Harl::mood[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
						<< std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"
						<< std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
						<< std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable ! I want to speak to the manager now."
						<< std::endl;
}

void Harl::complain( std::string level )
{
	int i = 0;
	static void (Harl::*log[])(void) =
		{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (level != mood[i])
		i++;
	return (this->*log[i])();
}