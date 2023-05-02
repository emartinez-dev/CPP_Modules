/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:15:26 by franmart          #+#    #+#             */
/*   Updated: 2023/05/02 17:56:54 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) :\
	 _name(name), _weapon(&weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack( void )
{
	if (!this->_weapon)
	{
		std::cerr << this->_name << " has no weapon, can't attack" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " \
		<< this->_weapon->getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	if (weapon.getType().empty())
	{
		std::cerr << "New weapon can't be empty" << std::endl;
		return ;
	}
	this->_weapon = &weapon;
}