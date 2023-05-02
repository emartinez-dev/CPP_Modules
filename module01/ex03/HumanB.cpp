/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:15:26 by franmart          #+#    #+#             */
/*   Updated: 2023/05/02 17:55:18 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack( void )
{
	if (!this->_weapon)
	{
		std::cerr << this->_name << " has no weapon, can't attack" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " \
		<< this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	if (weapon.getType().empty())
	{
		std::cerr << "New weapon can't be empty" << std::endl;
		return ;
	}
	this->_weapon = &weapon;
}