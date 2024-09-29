/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:51:30 by terussar          #+#    #+#             */
/*   Updated: 2023/12/17 21:41:57 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdio.h>

int main(void)
{
	std::string test;
	std::string *stringPTR;
	std::string	&stringREF = test;
	// test et &stringREF représentent la même variable, et celle-ci peut être
	// accédée et modifiée à l'aide de ces deux identificateurs indistinctement.
	test = "HI THIS IS BRAIN";
	stringPTR = &test;
	stringREF = "Change";
	
	printf("print different adress:\ntest = %p\n*stringPTR = %p\n&stringREF = %p\n\n", &test, stringPTR, &stringREF);
	printf("print different value:\ntest = %s\n*stringPTR = %s\n&stringREF = %s\n", test.c_str(), stringPTR->c_str(), stringREF.c_str());
	return (0);
}
