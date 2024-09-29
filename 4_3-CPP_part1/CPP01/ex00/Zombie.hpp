/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:16:58 by terussar          #+#    #+#             */
/*   Updated: 2023/11/24 16:30:44 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

class Zombie
{
private:
	std::string _name;
public:
	void announce(void);
	Zombie(std::string name);
	~Zombie();
};
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
