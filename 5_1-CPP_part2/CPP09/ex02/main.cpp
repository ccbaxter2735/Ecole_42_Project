/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:55:39 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 19:18:54 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkArg(std::string arg)
{
	std::istringstream iss(arg);
	std::string token;

	iss >> token;
	std::size_t i = -1;
	while (++i < token.size())
	{
		if (!isdigit(token[i]))
			return (false);
	}
	double result = strtod(arg.c_str(), NULL);
	if (result > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	int i = 0;
	
	if (ac == 1)
	{
		std::cerr << "Error: need at least one argument" << std::endl;
		return (1);
	}
	
	PmergeMe merge;

	while (++i < ac)
	{
		if (!checkArg(av[i]))
		{
			std::cerr << "Error: non positive int argument : " << av[i] << std::endl;
			return (1);
		}
	}
	
	i = 0;
	std::cout << "Before : ";
	while (++i < ac)
		std::cout << av[i] << " ";
	std::cout << std::endl;

	// Deque
	clock_t startDeque = clock();
	merge.fordJohnsonSortDeque(ac, av);
	clock_t endDeque = clock();
	std::cout << "Deque After : ";
	merge.showList();
	
	// Vector
	clock_t startVector = clock();
	merge.fordJohnsonSortVector(ac, av);
	clock_t endVector = clock();
	std::cout << "Vector After : ";
	merge.showList();

	double elapsedTimeDeque = (double(endDeque - startDeque) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << merge.getSizeDeque() << " elements with std::deque : " << elapsedTimeDeque << " us" << std::endl;
	double elapsedTimeVector = (double(endVector - startVector) / CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << merge.getSizeVector() << " elements with std::vector : " << elapsedTimeVector << " us" << std::endl;
	// vector Vs Deque
	// vector stocke dans tableau contigue / deque stoque dans liste chaine possible saut dans memoire
	return 0;
}

