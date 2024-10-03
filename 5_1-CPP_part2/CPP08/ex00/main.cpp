/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:42:00 by terussar          #+#    #+#             */
/*   Updated: 2024/03/28 14:02:48 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ()
{
  std::vector<int> myvector;
	int repNb;
	
  for (int i=0; i<=5; i++) myvector.push_back(i);
	std::cout << "------ Container initialization -------" << std::endl;
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl << std::endl;
	std::cout << "----------- example function ----------" << std::endl;
	std::cout << "Quelle valeur rechercher : ";
	std::cin >> repNb;
	if (std::cin.eof() || !std::cin.good())
	{
		std::cout << "error: EOF detected or not digit" << std::endl;
		return (1);
	}
	try
	{
		std::cout << "Valeur recherchee: " << repNb 
			<< " - easyfind result: ";
		easyfind(myvector, repNb);
		std::cout	<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
  return 0;
}