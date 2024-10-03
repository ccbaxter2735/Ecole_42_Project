/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:48:04 by terussar          #+#    #+#             */
/*   Updated: 2024/03/28 15:37:06 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << "------- Mandatory --------"<< std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(17);
		// sp.addNumber(50);
		
		std::cout << std::endl;
		std::cout << "smallest distance into span list: " << sp.shortestSpan() << std::endl;
		std::cout << "longuest distance into span list: " << sp.longestSpan() << std::endl;
		sp.showMember();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "------- Extra part --------"<< std::endl;
	try
	{
		int size;
		
		size = 0;
		while (1)
		{
			std::cout << "Quelle taille de span voulez vous (doit etre > 0 et <= 10 000) : ";
			std::cin >> size;
			if (size >= 1 && size <= 10000)
				break ;
			if (std::cin.eof() || std::cin.good())
				throw Span::WrongSpanSize();
			std::cout << "Wrong input retry... " << std::endl;
		}
		Span sp2 = Span(size);
		sp2.addNumbers(45, 15);
		std::cout << std::endl;
		std::cout << "sp2: ";
		sp2.showMember();
		std::cout << "smallest distance into span list: " << sp2.shortestSpan() << std::endl;
		std::cout << "longuest distance into span list: " << sp2.longestSpan() << std::endl;
		
		sp2.addNumbers(30, 45);
		std::cout << std::endl;
		std::cout << "sp2: ";
		sp2.showMember();
		std::cout << "smallest distance into span list: " << sp2.shortestSpan() << std::endl;
		std::cout << "longuest distance into span list: " << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
