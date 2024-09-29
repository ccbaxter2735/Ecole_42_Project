/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 22:44:08 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 16:50:55 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
#define SCRAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool _gate;
public:
	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap(const ScavTrap &oldScav);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void guardGate( void );
	ScavTrap &operator=(ScavTrap const &a);
	~ScavTrap();
};

#endif
