/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:17:59 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 20:51:40 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void msg_err_value(std::string value)
{
	int i;

	i = BitcoinExchange::valueIsValid(value);
	if (i == 1)
		std::cerr << "Error: not a number" << std::endl;
	if (i == 2)
		std::cerr << "Error: negative number" << std::endl;
	if (i == 3)
		std::cerr << "Error: too large number" << std::endl;
}

int main(int ac, char **av)
{
	BitcoinExchange btc("data.csv");
	std::ifstream file(btc.getName().c_str());
	std::string line;
	std::string date;
	std::string value;
	std::size_t pos_sep;
	std::string delimiter = " | ";
	
	if (ac == 2)
	{
		std::ifstream input(av[1]); //fichier input av date | value
		if (input.fail() || file.fail())
		{
			std::cerr << "Error: could not open input or database file." << std::endl;
			return (1);
		}
		std::getline(input, line); //ignore first line
		std::getline(input, line);
		btc.loadData();
		while (1)
		{
			if (line.size() == 0 && input.eof())
				break;
			pos_sep = line.find(" | ");
			
			if (pos_sep != 10 || line.size() < 14)
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				if (input.eof())
					break;
				getline(input, line);
				continue;
			}
			date = line.substr(0, line.find(delimiter));
			value = line.substr(line.find(delimiter) + delimiter.size(), line.find("\n"));
			if (BitcoinExchange::dateIsValid(date) == false)
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				if (input.eof())
					break;
				std::getline(input, line);
				continue;
			}
			if (BitcoinExchange::valueIsValid(value) != 0)
			{
				msg_err_value(value);
				if (input.eof())
					break;
				std::getline(input, line);
				continue;
			}
			std::cout << date << " => " << value << " = " << btc.calcul(date, value) << std::endl; // ajouter fct pour trouver valeur csv
			if (input.eof())
				break;
			std::getline(input, line);
		}
		input.close();
	}
	else
	{
		std::cerr << "Error: two arguments needed." << std::endl;
		return (1);
	}
	return (0);
}
