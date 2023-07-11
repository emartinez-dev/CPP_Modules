/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:33:58 by franmart          #+#    #+#             */
/*   Updated: 2023/07/11 12:30:08 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/* I have seen that inheriting HitPoints from FragTrap and EnergyPoints from
ScavTrap is not possible, because as ClapTrap class is virtual, there is only
one ClapTrap instance shared between ScavTrap and FragTrap, and they overlap
each other

Reference:
https://stackoverflow.com/questions/69033631/inheritance-from-parents-with-same-members
*/

DiamondTrap::DiamondTrap():ScavTrap(),FragTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->setHitPoints(FragTrap::_hitPoints);
	this->setEnergyPoints(ScavTrap::_energyPoints);
	this->setAttackDamage(FragTrap::_attackDamage);
}

DiamondTrap::DiamondTrap(std::string name):	ScavTrap(name),FragTrap(name)
{
	ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->setHitPoints(FragTrap::_hitPoints);
	this->setEnergyPoints(ScavTrap::_energyPoints);
	this->setAttackDamage(FragTrap::_attackDamage);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{ this->_name = copy.getName();
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
		this->_hitPoints = copy.getHitPoints();
	}
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
		this->_hitPoints = copy.getHitPoints();
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << ", also known as " << \
		ClapTrap::getName() << std::endl;
}
