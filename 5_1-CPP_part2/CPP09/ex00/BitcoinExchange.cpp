/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:37:45 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 20:37:46 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	this->_name = file;
}

std::string BitcoinExchange::getName( void )
{
	return (this->_name);
}

void BitcoinExchange::loadData( void )
{
	std::ifstream file(this->_name.c_str());
	std::string line;
	std::string date;
	std::string value;
	std::size_t pos_sep;
	std::string delimiter = ",";
	
	std::getline(file, line);
	std::getline(file, line);
	while (1)
	{
		if (line.size() == 0 && file.eof())
			break;
		pos_sep = line.find(delimiter);
		if (pos_sep != 10 || line.size() < 12)
		{
			this->_data.clear();
			std::cerr << "Error: bad 1input => " << line << std::endl;
			break;
		}
		date = line.substr(0, 10);
		value = line.substr(11, line.size() - 10);
		if (BitcoinExchange::dateIsValid(date) == false)
		{
			this->_data.clear();
			std::cerr << "Error: bad input => " << line << std::endl;
			break;
		}
		this->_data.insert(std::make_pair(date, strtod(value.c_str(), NULL)));
		// std::cout << std::setprecision(2) << std::setiosflags(std::ios::fixed); // pour mettre 2 chiffres apres la virgule
		std::getline(file, line);
	}
	file.close();
}

bool BitcoinExchange::yearIsBissextile(int year)
{
  if (year % 400 == 0) {
    return (true);
  }
  else if (year % 100 == 0) {
    return (false);
  }
  else if (year % 4 == 0) {
    return (true);
  }
  return (false);
}

bool BitcoinExchange::dateIsValid(std::string date)
{
	double year = strtod(date.substr(0, 4).c_str(), NULL);
	double month = strtod(date.substr(5, 2).c_str(), NULL);
	double day = strtod(date.substr(8, 2).c_str(), NULL);
	
	// test date
	if (date.size() != 10 || date.at(4) != '-' || date.at(7) != '-')
		return (false);
	if (year < 2009 || year > 2022 || day < 1 || day > 31 || static_cast<double>(static_cast<int>(year)) != year)
		return (false);
	if (month > 12 || month < 1 || static_cast<double>(static_cast<int>(month)) != month)
		return (false);
	if (month == 2 && yearIsBissextile(static_cast<int>(year)) == false && day > 28)
		return (false);
	if (month == 2 && yearIsBissextile(static_cast<int>(year)) == true && day > 29)
		return (false);
	if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	else
		return (true);
}

int BitcoinExchange::valueIsValid(std::string value)
{
	char *remain = NULL;
	double db = strtod(value.c_str(), &remain);
	std::string reste(remain);

	if (!reste.empty())
		return (1);
	if (db < 0)
		return (2);
	if (db > 1000)
		return (3);
	return (0);
}

double BitcoinExchange::calcul(std::string date, std::string search)
{
	double qt;
	std::map<std::string, double>::iterator exTrade = --this->_data.upper_bound(date);
	if (exTrade != this->_data.end())
		qt = strtod(search.c_str(), NULL);
	else
		return (0);
	return (qt * exTrade->second);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	if (this != &copy)
	{
		this->_data.clear();
		this->_data = copy._data;
		this->_name = copy._name;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}