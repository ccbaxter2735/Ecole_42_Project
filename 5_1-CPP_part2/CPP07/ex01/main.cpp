/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:34:41 by terussar          #+#    #+#             */
/*   Updated: 2024/03/27 20:30:29 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void )
{
	std::string tabString[3] = {"je", "suis", "la"};
	int tabInt[4] = {1, 2, 3, 4};
	
	iter(tabInt, 4, functionTest<int>);
	iter(tabString, 3, functionTest<std::string>);
	return (0);
}
