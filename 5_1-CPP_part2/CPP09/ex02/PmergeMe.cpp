/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:56:05 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 19:18:15 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

// ---------------------- DEQUE ------------------------------------------------------------------------
void PmergeMe::fordJohnsonSortDeque(int ac, char **av) 
{
	if (ac == 2)
	{
		this->myDeque.push_back(this->castInt(av[1]));
		return;
	}  // Si la taille de la deque est 1, elle est déjà triée

	std::deque< std::pair<int, int> > pairDeque;
	int last = 0;
	int size = ac - 1;
	bool isPair = true;

	if (size % 2 != 0) // regarder et retenir dernier si impair
	{
		last = this->castInt(av[size]);
		size--;
		isPair = false;
	}
	// formation des pairs
	for (int i = 1; i < size; i += 2)
		pairDeque.push_back(std::make_pair(this->castInt(av[i]), this->castInt(av[i + 1])));
	// tri par paire
	for (std::deque< std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	// ordonner les pairs par plus grand nb
	this->mergeSortRecurDeque(pairDeque, 0, pairDeque.size() - 1);
	// ajouter les grandes valeurs dans sortedDeque
	for (std::deque< std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
		this->myDeque.push_back(it->second);
	// inserer les petites valeurs
	for (std::deque< std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
		this->myDeque.insert(this->myDeque.begin() + this->findPositionDeque(it->first), it->first);	
	if (!isPair)
		this->myDeque.insert(this->myDeque.begin() + this->findPositionDeque(last), last);
}

void PmergeMe::mergeSortRecurDeque(std::deque< std::pair<int, int> > &pairDeque, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		this->mergeSortRecurDeque(pairDeque, left, middle);
		this->mergeSortRecurDeque(pairDeque, middle + 1, right);
		this->sortArrayDeque(pairDeque, left, middle, right);
	}
}

void PmergeMe::sortArrayDeque(std::deque< std::pair<int, int> > &pairDeque, int left, int middle, int right)
{
	int partLeft = middle - left + 1;
	int partRight = right - middle;

	std::deque< std::pair<int, int> > bufLeft;
	std::deque< std::pair<int, int> > bufRight;

	for (int i = 0; i < partLeft; i++)
		bufLeft.push_back(pairDeque[left + i]);
	for (int i = 0; i < partRight; i++)
		bufRight.push_back(pairDeque[middle + 1 + i]);
	for (int i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < partLeft) && (j >= partRight || bufLeft[i].second <= bufRight[j].second))
		{
			pairDeque[k] = bufLeft[i];
			i++;
		}
		else
		{
			pairDeque[k] = bufRight[j];
			j++;
		}
	}
}

// ---------------------- VECTOR ------------------------------------------------------------------------
void PmergeMe::fordJohnsonSortVector(int ac, char **av) 
{
	if (ac == 2)
	{
		this->myVector.push_back(this->castInt(av[1]));
		return;
	}  // Si la taille de la deque est 1, elle est déjà triée

	std::vector< std::pair<int, int> > pairVector;
	int last = 0;
	int size = ac - 1;
	bool isPair = true;

	if (size % 2 != 0) // regarder et retenir dernier si impair
	{
		last = this->castInt(av[size]);
		size--;
		isPair = false;
	}
	// formation des pairs
	for (int i = 1; i < size; i += 2)
		pairVector.push_back(std::make_pair(this->castInt(av[i]), this->castInt(av[i + 1])));
	// tri par paire
	for (std::vector< std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	// ordonner les pairs par plus grand nb
	this->mergeSortRecurVector(pairVector, 0, pairVector.size() - 1);
	// ajouter les grandes valeurs dans sortedDeque
	for (std::vector< std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
		this->myVector.push_back(it->second);
	// inserer les petites valeurs
	for (std::vector< std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
		this->myVector.insert(this->myVector.begin() + this->findPositionVector(it->first), it->first);	
	if (!isPair)
		this->myVector.insert(this->myVector.begin() + this->findPositionVector(last), last);
}

void PmergeMe::mergeSortRecurVector(std::vector< std::pair<int, int> > &pairVector, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		this->mergeSortRecurVector(pairVector, left, middle);
		this->mergeSortRecurVector(pairVector, middle + 1, right);
		this->sortArrayVector(pairVector, left, middle, right);
	}
}

void PmergeMe::sortArrayVector(std::vector< std::pair<int, int> > &pairVector, int left, int middle, int right)
{
	int partLeft = middle - left + 1;
	int partRight = right - middle;

	std::vector< std::pair<int, int> > bufLeft;
	std::vector< std::pair<int, int> > bufRight;

	for (int i = 0; i < partLeft; i++)
		bufLeft.push_back(pairVector[left + i]);
	for (int i = 0; i < partRight; i++)
		bufRight.push_back(pairVector[middle + 1 + i]);
	for (int i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < partLeft) && (j >= partRight || bufLeft[i].second <= bufRight[j].second))
		{
			pairVector[k] = bufLeft[i];
			i++;
		}
		else
		{
			pairVector[k] = bufRight[j];
			j++;
		}
	}
}

int PmergeMe::findPositionVector(int value)
{
	int left = 0;
	int right = this->getSizeVector();
	int middle;

	while (left < right)
	{
		middle = (left + right) / 2;
		if (this->myVector[middle] > value)
			right = middle;
		else
			left = middle + 1;
	}
	return (right);
}


// cherche position ou mettre la valeur par decoupe en moitie
int PmergeMe::findPositionDeque(int value)
{
	int left = 0;
	int right = this->getSizeDeque();
	int middle;

	while (left < right)
	{
		middle = (left + right) / 2;
		if (this->myDeque[middle] > value)
			right = middle;
		else
			left = middle + 1;
	}
	return (right);
}

int PmergeMe::castInt( std::string arg )
{
	std::istringstream iss(arg);
	int result;
	iss >> result;
	return (result);
}

int PmergeMe::getSizeDeque( void )
{
	return (this->myDeque.size());
}

int PmergeMe::getSizeVector( void )
{
	return (this->myVector.size());
}

void PmergeMe::showList( void )
{
	for (std::deque<int>::iterator it = this->myDeque.begin(); it != this->myDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

const char* PmergeMe::NumberOverflow::what() const throw()
{
	return ("Error: int overflow");
}

PmergeMe::~PmergeMe()
{
}