/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:19 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 14:34:29 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat bob;
	Form ultimateForm;
	
	// Bureaucrat
	try
	{
		bob = Bureaucrat("Bob", 150);
		std::cout << bob;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "----------------------" << std::endl;
	// Form initialization
	try
	{
		ultimateForm = Form("ultime contract", 149, 5);
		std::cout << ultimateForm;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "----------------------" << std::endl;
	// Form try to sign first time
	try
	{
		bob.signForm( ultimateForm );
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "----------------------" << std::endl;
	// upgrade bob to sign
	try
	{
		bob.upGrade();
		std::cout << bob;
		bob.signForm( ultimateForm );
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
