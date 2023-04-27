/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:42:28 by franmart          #+#    #+#             */
/*   Updated: 2023/04/27 12:57:26 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->getNbAccounts();
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	Account::_nbAccounts--;
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t	now;
	tm		*local;

	now = time(0);
	local = localtime(&now);
	std::cout << std::setfill('0') << "[" << local->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << local->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << local->tm_sec << "] ";
}
