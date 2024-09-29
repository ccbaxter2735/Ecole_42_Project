/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:57:07 by terussar          #+#    #+#             */
/*   Updated: 2023/12/29 16:12:04 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:

	public:
		Brain();
		Brain(const Brain &a);
		Brain &operator=(const Brain &a);
		std::string ideas[100];
		~Brain();
};

#endif
