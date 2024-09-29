/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:39:33 by terussar          #+#    #+#             */
/*   Updated: 2023/12/17 21:44:34 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _armeB(NULL)
{
	_name = name;
}

void HumanB::setWeapon(Weapon &armeB)
{
	_armeB = &armeB;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	if (_armeB == NULL)
		std::cout << _name << " attacks with their fists" << std::endl;
	else
		std::cout << _name << " attacks with their " << _armeB->getType() << std::endl;
}
