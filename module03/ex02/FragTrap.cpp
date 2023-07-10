/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:07:03 by franmart          #+#    #+#             */
/*   Updated: 2023/07/10 18:07:18 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy.getName();
		this->_attackDamage = copy.getAttackDamage();
		this->_energyPoints = copy.getEnergyPoints();
		this->_hitPoints = copy.getHitPoints();
	}
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
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

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " is asking for a high five!" \
		<< std::endl;
}
