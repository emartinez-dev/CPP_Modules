/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:33:58 by franmart          #+#    #+#             */
/*   Updated: 2023/05/22 16:18:33 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap()
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(50);
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name_private = name;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(50);
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy):ClapTrap(copy)
{
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy);
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string target)
{
	ScavTrap::setClassname("ScavTrap");
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name_private << ", also known as " << \
		ClapTrap::getName() << std::endl;
}
