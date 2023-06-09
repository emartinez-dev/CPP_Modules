/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:47:59 by franmart          #+#    #+#             */
/*   Updated: 2023/07/10 08:58:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}


ClapTrap::ClapTrap(std::string const &name):_name(name), _hitPoints(10),\
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
		this->_hitPoints = copy.getHitPoints();
	}
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
		this->_hitPoints = copy.getHitPoints();
	}
	return (*this);
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->_attackDamage;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "No energy points left, can't attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "\
		<< this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " was attacked, receiving " << amount\
		<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "No energy points left, can't be repaired!" << std::endl;
		return;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " was repaired " << amount << \
		" points of HP, it now has " << this->_hitPoints << " points." << std::endl;
}
