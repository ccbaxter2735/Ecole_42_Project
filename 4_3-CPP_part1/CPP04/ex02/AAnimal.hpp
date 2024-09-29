/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:16:50 by terussar          #+#    #+#             */
/*   Updated: 2023/12/30 18:07:48 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal &a);
	AAnimal &operator=(const AAnimal &a);
	virtual void makeSound(void) const = 0;
	std::string getType( void ) const;
	virtual ~AAnimal();
};

#endif