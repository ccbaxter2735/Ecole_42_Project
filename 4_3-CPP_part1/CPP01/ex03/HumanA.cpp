/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:39:03 by terussar          #+#    #+#             */
/*   Updated: 2023/11/28 19:10:19 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &armeA) : _armeA(armeA)
{
	_name = name;
}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _armeA.getType() << std::endl;
}

HumanA::~HumanA()
{
}