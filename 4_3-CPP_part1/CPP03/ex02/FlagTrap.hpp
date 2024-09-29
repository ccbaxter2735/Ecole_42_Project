/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:01:28 by terussar          #+#    #+#             */
/*   Updated: 2023/12/28 17:04:41 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
private:

public:
	FlagTrap();
	FlagTrap( std::string name );
	FlagTrap(const FlagTrap &oldFlag);
	void highFivesGuys(void);
	FlagTrap &operator=(FlagTrap const &a);
	~FlagTrap();
};

#endif