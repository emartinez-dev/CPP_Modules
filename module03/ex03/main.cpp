/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:14:52 by franmart          #+#    #+#             */
/*   Updated: 2023/07/11 12:05:52 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include <ostream>

int	main(void)
{
	DiamondTrap	trap("Foo");

	std::cout << "Attack damage: " << trap.getAttackDamage() << "\nHP: " << \
		trap.getHitPoints() << "\nEP: " << trap.getEnergyPoints() << std::endl;
	trap.attack("Bar");
	trap.whoAmI();
	trap.guardGate();
	trap.highFivesGuys();
	return (0);
}