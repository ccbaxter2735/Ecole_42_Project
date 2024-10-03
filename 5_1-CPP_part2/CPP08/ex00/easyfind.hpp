/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:41:52 by terussar          #+#    #+#             */
/*   Updated: 2024/03/29 12:34:21 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cstdlib>

template <class T>
void easyfind(T &arg, int to_find)
{
	if (std::find(arg.begin(), arg.end(), to_find) != arg.end())
		std::cout << "int value " << to_find << " found" << std::endl;
	else
		throw std::runtime_error("error: value not found");
}

#endif
