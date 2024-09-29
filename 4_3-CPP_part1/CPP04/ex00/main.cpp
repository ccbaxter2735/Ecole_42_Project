/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:14:39 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 15:20:11 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();

	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << j->getType() << " must show Dog" << std::endl;
	std::cout << i->getType() << " must show Cat" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl << "----------------------------------" << std::endl;
	std::cout << k->getType() << " must show WrongCat" << std::endl;
	std::cout << meta2->getType() << " must show WrongAnimal" << std::endl;
	k->makeSound();
	meta2->makeSound();
		std::cout << std::endl << "----------------------------------" << std::endl;
	delete meta;
	delete meta2;
	delete i;
	delete j;
	delete k;
	return 0;
}
