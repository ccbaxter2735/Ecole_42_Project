#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int test_mandatory(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}


void test_int(void)
{
	Array<int> nb(10);
	Array<int> nb2;
	srand(time(NULL));
	std::cout << "----------------- ARRAY INT ------------------" << std::endl;
	std::cout << "----------------- init value rand ------------------" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		nb[i] = rand();
	}
	for (int j = 0; j < 10; j++)
	{
		try
		{
			std::cout << "index = " << j << " --> " <<nb[j] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// test modification
	std::cout << std::endl << "----------------- test modification ------------------" << std::endl;
	try
	{
		nb[2] = 25;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int j = 0; j < 10; j++)
	{
		try
		{
			std::cout << "index = " << j << " --> " << nb[j] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// test exception
	std::cout << std::endl << "---- test exception (tous les exemples doivent renvoyer exception) ----" << std::endl;
	try
	{
		std::cout << "index = -1" << " --> ";
		nb[-1] = 25;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "index = size" << " --> ";
		nb[nb.size()] = 25;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// test recopie
	std::cout << std::endl << "------------------------ test copy ---------------------------" << std::endl;
	Array<int> tmp = nb;
	Array<int> test(tmp);
}

void test_char(void)
{
	Array<char> character(5);
	Array<char> nb2;
	int value;
	srand(time(NULL));
	std::cout << std::endl << "----------------- ARRAY CHAR ------------------" << std::endl;
	std::cout << "----------------- init value rand ------------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			value = rand() % 126;
			if (value < 127 && value > 32)
			{
				character[i] = value;
				break ;
			}
		}
	}
	for (int j = 0; j < 5; j++)
	{
		try
		{
			std::cout << "index = " << j << " --> " << character[j] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// test modification
	std::cout << std::endl << "----------------- test modification ------------------" << std::endl;
	try
	{
		character[2] = 'q';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int j = 0; j < 5; j++)
	{
		try
		{
			std::cout << "index = " << j << " --> " << character[j] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// test exception
	std::cout << std::endl << "---- test exception (tous les exemples doivent renvoyer exception) ----" << std::endl;
	try
	{
		std::cout << "index = -1" << " --> ";
		character[-1] = 25;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "index = size" << " --> ";
		character[character.size()] = 25;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// test recopie
	std::cout << std::endl << "------------------------ test copy ---------------------------" << std::endl;
	Array<char> tmp = character;
	Array<char> test(tmp);
}

int main()
{
	test_mandatory();
	test_int();
	test_char();
	return (0);
}