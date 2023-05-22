/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:11:12 by franmart          #+#    #+#             */
/*   Updated: 2023/05/22 12:59:34 by franmart         ###   ########.fr       */
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
	this->setClassname("ScavTrap");
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setClassname("ScavTrap");
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << this->getClassname() << " " << this->getName() \
		<< " is now in Gate keeper mode\n";
}
