/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:56:56 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 17:41:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "manger, lecher .... manger, lecher ....";
}

Brain::Brain(const Brain &a)
{
	*this = a;
}

Brain &Brain::operator=(const Brain &a)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = a.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Default Brain Destructor called" << std::endl;
}