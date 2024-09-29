/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:14:39 by terussar          #+#    #+#             */
/*   Updated: 2023/12/30 17:55:11 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << std::endl << "----------------------------------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	std::cout << std::endl << "----------------------------------" << std::endl;
	const Animal *tab_anim[20];
	for(int i = 0; i < 10; i++)
		tab_anim[i] = new Dog();
	for(int i = 10; i < 20; i++)
		tab_anim[i] = new Cat();
	std::cout << tab_anim[0]->getType() << " " << static_cast<const Dog *>(tab_anim[0])->getBrain() << " shoud be a Dog" << std::endl;
	std::cout << tab_anim[9]->getType() << " shoud be a Dog" << std::endl;
	std::cout << tab_anim[10]->getType() << " shoud be a Cat" << std::endl;
	
	std::cout << std::endl << "----------------------------------" << std::endl;
	for(int i = 0; i < 20; i++)
		delete tab_anim[i];
	
	std::cout << std::endl << "----------------------------------" << std::endl;
	Dog *basic = new Dog();
	Dog *tmp = new Dog();
	// tmp = new Dog(*basic);
	*tmp = *basic;
	delete basic;
	tmp->makeSound();
	std::cout << tmp->getType() << " it's good deep copy because we can show it so that basic is deleted" << std::endl;
	delete tmp;
	return 0;
}
