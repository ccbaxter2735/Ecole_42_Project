/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:34:59 by terussar          #+#    #+#             */
/*   Updated: 2024/03/27 20:22:57 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T, typename F>
void iter(T *array, std::size_t size, F fct)
{
	std::size_t i = 0;

	while (i < size)
	{
		fct(array[i]);
		i++;
	}
}

template <class T>
void functionTest(T &e)
{
	std::cout << e << std::endl;
}

#endif