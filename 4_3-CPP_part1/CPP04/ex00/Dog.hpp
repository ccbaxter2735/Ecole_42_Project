/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:45 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 20:35:14 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog();
	Dog(const Dog &a);
	Dog&operator=(const Dog &a);
	void makeSound(void) const;
	~Dog();
};

#endif