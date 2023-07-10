/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:11:12 by franmart          #+#    #+#             */
/*   Updated: 2023/07/10 18:05:51 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
		this->_hitPoints = copy.getHitPoints();
	}
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
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

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() \
		<< " is now in Gate keeper mode\n";
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "No energy points left, can't attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << \
		target << ", causing " << this->_attackDamage << " points of damage!\n";
}
