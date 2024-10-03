/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:38:00 by terussar          #+#    #+#             */
/*   Updated: 2024/04/04 20:36:16 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <cstring>
# include <map>
# include <iostream>
# include <limits>
# include <sstream>
# include <cstdlib>
# include <fstream>
# include <utility>
# include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
		std::string _name;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string file);
		void loadData( void );
		std::string getName( void );
		BitcoinExchange(BitcoinExchange const &copy);
		static bool yearIsBissextile(int year);
		static bool dateIsValid(std::string date);
		static int valueIsValid(std::string value);
		double calcul(std::string value, std::string search);
		BitcoinExchange &operator=(BitcoinExchange const &copy);
		~BitcoinExchange();
};


#endif