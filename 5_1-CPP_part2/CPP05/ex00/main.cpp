/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:34:19 by terussar          #+#    #+#             */
/*   Updated: 2024/02/19 11:52:29 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat bob("Bob", 10);
		// show name and grade
		std::cout << bob;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "--------------------" << std::endl;
	try
	{
		Bureaucrat jak("Jak", 2);
		jak.upGrade();
		// show name and grade
		std::cout << jak;
		jak.downGrade();
		// show name and grade
		std::cout << jak;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "--------------------" << std::endl;
	try
	{
		Bureaucrat paul("Paul", 149);
		paul.downGrade();
		// show name and grade
		std::cout << paul;
		paul.downGrade();
		// show name and grade
		std::cout << paul;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
