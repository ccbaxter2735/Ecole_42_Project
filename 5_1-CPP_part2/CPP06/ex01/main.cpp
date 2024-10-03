/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:33:15 by terussar          #+#    #+#             */
/*   Updated: 2024/02/23 17:58:27 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data origin;
	uintptr_t result_serialize;
	Data *result_deserialize;

	origin.nb = 1000;
	origin.str = "Ecole42";
	
	std::cout << "------ origin -------" << std::endl;
	std::cout << "&origin: " << &origin << std::endl;
	std::cout << "origin.nb: " << origin.nb << std::endl;
	std::cout << "origin.str: " << origin.str << std::endl;
	
	std::cout << std::endl << "------ serialize -------" << std::endl;
	result_serialize = Serializer::serialize(&origin);
	std::cout << "&result_serialize: " << &result_serialize << std::endl;
	std::cout << "result_serialize: " << result_serialize << std::endl;

	std::cout << std::endl << "------ deserialize -------" << std::endl;
	result_deserialize = Serializer::deserialize(result_serialize);
	std::cout << "result_deserialize: " << result_deserialize << std::endl;
	std::cout << "result_deserialize.nb: " << result_deserialize->nb << std::endl;
	std::cout << "result_deserialize.str: " << result_deserialize->str << std::endl;
	
	return 0;
}
