/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:14:52 by franmart          #+#    #+#             */
/*   Updated: 2023/07/10 09:23:57 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ScavTrap	trap("Foo");

	trap.setEnergyPoints(0);
	trap.attack("Bar");
	trap.setEnergyPoints(100);
	trap.attack("Bar");
	trap.takeDamage(10);
	trap.beRepaired(20);
	trap.guardGate();
	return (0);
}