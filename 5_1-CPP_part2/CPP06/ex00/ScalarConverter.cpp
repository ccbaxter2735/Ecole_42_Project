/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:50:01 by terussar          #+#    #+#             */
/*   Updated: 2024/03/26 16:32:39 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default scalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return (*this);
}

void	ScalarConverter::convert_char(std::string str)
{
	char c;

	c = str.c_str()[0];
	if (c < 32 || c > 126)
		std::cout << "char: non displayable" << std::endl;
	else if (c < 0)
		std::cout << "char: no char for negative value" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed); // format d ecriture . et chiffres significatifs
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	ScalarConverter::convert_int(double x)
{
	int nb = static_cast<int>(x);
	// if int overflow
	if (x == static_cast<double>(nb))
	{
		if (nb < static_cast<int>(std::numeric_limits<char>::min()) || nb > static_cast<int>(std::numeric_limits<char>::max()))
			std::cout << "char: impossible " << std::endl;
		else if (nb < 32 || nb > 126)
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(x) << std::endl;
		std::cout << std::setprecision(1) << std::setiosflags(std::ios::fixed); // format d ecriture . et chiffres significatifs
		std::cout << "float: " << static_cast<float>(x) << 'f' << std::endl;
		std::cout << "double: " << x << std::endl;
		return ;
	}
	else
	{
		std::cout << "char: int overflow, impossible conversion" << std::endl;
		std::cout << "int: int overflow, impossible conversion" << std::endl;
		std::cout << "double: int overflow, impossible conversion" << std::endl;
		std::cout << "float: int overflow, impossible conversion" << std::endl;
	}

}

void ScalarConverter::convert_float(double x, std::string str)
{
	float f = static_cast<float>(x);
	int prc = str.size() - 2 - str.find('.'); // refaire qq test

	if (std::abs(x) < std::numeric_limits<float>::min() || x > std::numeric_limits<float>::max())
	{
		std::cout << "char: float overflow, impossible conversion" << std::endl;
		std::cout << "int: float overflow, impossible conversion" << std::endl;
		std::cout << "double: float overflow, impossible conversion" << std::endl;
		std::cout << "float: float overflow, impossible conversion" << std::endl;
	}
	else
	{
		if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else if (static_cast<char>(f) < 32 || static_cast<char>(f) > 126) // voir limite int
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		if (x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max())
			std::cout << "int: int overflow" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(x) << std::endl;
		std::cout << std::setprecision(prc) << std::setiosflags(std::ios::fixed);
		std::cout << "float: " << f << 'f' << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::convert_double(double x, std::string str)
{
	int prc = str.size() - 1 - str.find('.'); // refaire qq test
	
	if ((static_cast<char>(x) >= 0 && static_cast<char>(x) < 32) || static_cast<char>(x) > 126) // voir limite int
		std::cout << "char: no displayable" << std::endl;
	else if (x < 0)
		std::cout << "char: no char for negative value" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(x) << "'" << std::endl;
	if (x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max())
		std::cout << "int: int overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	if (x < std::numeric_limits<float>::min() || x > std::numeric_limits<float>::max())
		std::cout << "float: float overflow" << std::endl;
	else
	{
		std::cout << std::setprecision(prc) << std::setiosflags(std::ios::fixed);
		std::cout << "float: " << static_cast<float>(x) << 'f' << std::endl;
	}
	std::cout << "double: " << x << std::endl;
}

void ScalarConverter::convert_nan(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert_inf(bool bo)
{
	if (bo == true)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void		ScalarConverter::convert(std::string str)
{
	// char
	if (str.size() == 1 && !isdigit(str.c_str()[0]))
	{
		ScalarConverter::convert_char(str);
		return ;
	}
	
	char	*remain = NULL;
	double	db = strtod(str.c_str(), &remain); //strtod convert string to double
	std::string remain_string(remain);

	// literal
	if (db != db && (remain_string.empty() || remain_string == "f" || remain_string == "F")) // NAN
	{
		ScalarConverter::convert_nan();
		return ;
	}
	if (isinf(db) && (remain_string.empty() || remain_string == "f" || remain_string == "F"))
	{
		if (db < 0)
			ScalarConverter::convert_inf(false);
		else
			ScalarConverter::convert_inf(true);
		return ;
	}
	// int
	if (!str.empty() && remain_string.empty() && str.find('.') == std::string::npos)
	{
		ScalarConverter::convert_int(db);
		return ;
	}
	// float
	if (!str.empty() && (remain_string == "f" || remain_string == "F") && str.find('.') != std::string::npos)
	{
		ScalarConverter::convert_float(db, str);
		return ;
	}
	// double
	if (!str.empty() && str.find('.') != std::string::npos && remain_string.empty())
	{
		ScalarConverter::convert_double(db, str);
		return ;
	}
	// else
	
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Default scalarConverter destructor called" << std::endl;
}