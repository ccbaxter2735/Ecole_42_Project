/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:14:39 by terussar          #+#    #+#             */
/*   Updated: 2024/09/12 13:02:22 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const AAnimal *meta = new AAnimal();
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << j->getType() << " must show Dog" << std::endl;
	std::cout << i->getType() << " must show Cat" << std::endl;
	i->makeSound();
	j->makeSound();
	// meta->makeSound();
	std::cout << std::endl << "----------------------------------" << std::endl;
	// delete meta;
	delete i;
	delete j;
	return 0;
}
