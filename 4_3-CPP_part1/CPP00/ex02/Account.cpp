/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terussar <terussar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:08:08 by terussar          #+#    #+#             */
/*   Updated: 2023/11/26 23:26:43 by terussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_nbAccounts++;
  _accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
						<< "amount:" << _amount << ";"
						<< "created" << std::endl;
}

Account::~Account( void ) // comment inverser le close ?????????
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
						<< "amount:" << _amount << ";"
						<< "closed" << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts() << ";"
					<< "amount:" << getTotalAmount() << ";"
					<< "deposit:" << getNbDeposits() << ";"
					<< "withdrawals:" << getNbWithdrawals() << ";" 
					<< std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
						<< "amount:" << _amount << ";"
						<< "deposits:" << _nbDeposits << ";"
						<< "withdrawals:" << _nbWithdrawals << ";"
						<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";"
					<< "p_amount:" << _amount << ";"
					<< "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";"
					<< "nb_deposit:" << _nbDeposits << ";"
					<< std::endl;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
					<< "p_amount:" << _amount << ";";
	if (_amount >= withdrawal)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";"
						<< "amount:" << _amount << ";"
						<< "nb_withdrawals:" << _nbDeposits << ";"
						<< std::endl;
		_totalAmount -= withdrawal;
		return (0);
	}
	else
		std::cout << "withdrawal:refused" << std::endl;
	return (1);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void Account::_displayTimestamp(void)
{
	time_t result = time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + localtime(&result)->tm_year
		<< std::setw(2) << 1 + localtime(&result)->tm_mon
		<<  std::setw(2) << localtime(&result)->tm_mday
		<<  "_"
		<<  std::setw(2) << localtime(&result)->tm_hour
		<<  std::setw(2) << localtime(&result)->tm_min
		<<  std::setw(2) << localtime(&result)->tm_sec 
		<< "] " << std::flush;
}
