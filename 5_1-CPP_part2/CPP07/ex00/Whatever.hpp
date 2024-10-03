/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:34:59 by terussar          #+#    #+#             */
/*   Updated: 2024/02/16 15:56:55 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <class T>
void swap(T &x, T &y)
{
  T tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template <class T>
T min(T x, T y)
{
  return (x < y ? x : y);
}

template <class T>
T max(T x, T y)
{
  return (x > y ? x : y);
}

#endif