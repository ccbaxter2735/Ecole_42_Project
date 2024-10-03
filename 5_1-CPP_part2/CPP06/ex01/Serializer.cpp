/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:39 by terussar          #+#    #+#             */
/*   Updated: 2024/02/23 16:40:32 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{
	std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
	return ;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void) copy;
	return (*this);
}

// reinterpret_cast autorize conversion fron pointer to other type of pointer
// uintptr_t is an unsigned integer type that is able of storing a data pointer
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

Serializer::~Serializer()
{
	std::cout << "Default destructor called" << std::endl;
}
