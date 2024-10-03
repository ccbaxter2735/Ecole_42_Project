/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:33:15 by terussar          #+#    #+#             */
/*   Updated: 2024/02/23 19:42:54 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	int clas;
	Base *base_ptr;
	srand((unsigned int)time(NULL)); //init rand

	base_ptr = NULL;
	clas = rand() % 3;
	std::cout << "rand = " << clas << std::endl;

	switch (clas)
	{
	case 0:
		std::cout << "Init A()" << std::endl;
		base_ptr = new A();
		break;
	case 1:
		std::cout << "Init B()" << std::endl;
		base_ptr = new B();
		break;
	case 2:
		std::cout << "Init C()" << std::endl;
		base_ptr = new C();
		break;
	default:
		break;
	}
	return (base_ptr);
}

void identify(Base* p)
{
	// dynamic cast return null si types incompatible
	A	*ptr_A = dynamic_cast<A *>(p);
	if (ptr_A == NULL)
	{
		B	*ptr_B = dynamic_cast<B *>(p);
		if (ptr_B == NULL)
		{
			C	*ptr_C = dynamic_cast<C *>(p);
			if (ptr_C == NULL)
				std::cerr << "Error, no type is matching" << std::endl;
			else
				std::cout << "identify .... : C" << std::endl;
		}
		else
			std::cout << "identify .... : B" << std::endl;
	}
	else
		std::cout << "identify .... : A" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A	&ptr_A = dynamic_cast<A &>(p);
		std::cout << "identify .... : A - adress : " << &ptr_A << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B	&ptr_B = dynamic_cast<B &>(p);
			std::cout << "identify .... : B - adress : " << &ptr_B << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C	&ptr_C = dynamic_cast<C &>(p);
				std::cout << "identify .... : C - adress : " << &ptr_C << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "conversion impossible" << std::endl;
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main()
{
	Base *base_ptr;
	Base base;
	std::cout << "------ Generate -------" << std::endl;
	base_ptr = generate();
	std::cout << std::endl << "------ identify by ptr -------" << std::endl;
	identify(base_ptr);
	std::cout << "should print no type: ";
	identify(&base);

	std::cout << std::endl << "------ identify by adress -------" << std::endl;
	identify(*base_ptr);
	std::cout << "should print no type: ";
	identify(base);
	delete(base_ptr);
	return 0;
}
