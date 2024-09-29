/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:16:58 by terussar          #+#    #+#             */
/*   Updated: 2023/11/25 20:39:08 by terussar         ###   ########.fr       */
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
	Zombie();
	void namedZombie(std::string name);
	void announce(void);
	~Zombie();
};
Zombie *zombieHorde( int N, std::string name );

#endif
