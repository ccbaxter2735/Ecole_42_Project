/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:51:19 by terussar          #+#    #+#             */
/*   Updated: 2023/11/25 20:48:00 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name;
	int N;
	
	std::cout << "what's the name of your zombie ? ";
	std::cin >> name;
	if (std::cin.eof())
		return (1);
	
	std::cout << "create zombie in the heap" << std::endl;
	std::cout << "how many zombie do you want in your horde ? ";
	std::cin >> N;
	if (std::cin.eof())
		return (1);

	Zombie *horde = zombieHorde(N, name);
	delete[] horde;
	return (0);
}
