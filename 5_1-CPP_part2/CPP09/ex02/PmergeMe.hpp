/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:56:09 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 19:03:44 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>

class PmergeMe
{
private:
	std::deque<int> myDeque;
	std::vector<int> myVector;
public:
	PmergeMe();
	void fordJohnsonSortDeque(int ac, char **av);
	void showList( void );
	int getSizeDeque( void );
	int castInt( std::string arg );
	int findPositionDeque(int value);
	void mergeSortRecurDeque(std::deque< std::pair<int, int> > &pairDeque, int left, int right);
	void sortArrayDeque(std::deque< std::pair<int, int> > &pairDeque, int left, int middle, int right);

	void fordJohnsonSortVector(int ac, char **av);
	int findPositionVector(int value);
	int getSizeVector( void );
	void mergeSortRecurVector(std::vector< std::pair<int, int> > &pairDeque, int left, int right);
	void sortArrayVector(std::vector< std::pair<int, int> > &pairDeque, int left, int middle, int right);

	class NumberOverflow : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	~PmergeMe();
};

#endif