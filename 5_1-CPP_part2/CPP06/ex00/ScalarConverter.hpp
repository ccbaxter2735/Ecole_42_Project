/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:49:46 by terussar          #+#    #+#             */
/*   Updated: 2024/03/26 14:22:07 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <limits>  
# include <iomanip>
# include <ostream>
# include <cmath>
# include <math.h>
# include <sstream>

class ScalarConverter
{
private:
	ScalarConverter( void );
	ScalarConverter( ScalarConverter const &copy );
	static void convert_char(std::string str);
	static void convert_int(double x);
	static void convert_float(double x, std::string str);
	static void convert_double(double x, std::string str);
	static void convert_nan(void);
	static void convert_inf(bool bo);
public:
	~ScalarConverter( void );
	static void convert(std::string str);
	ScalarConverter &operator=(const ScalarConverter &copy);
	
};




#endif