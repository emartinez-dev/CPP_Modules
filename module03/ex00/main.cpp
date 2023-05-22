/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:14:52 by franmart          #+#    #+#             */
/*   Updated: 2023/05/22 13:01:36 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trap("Foo");

	trap.setEnergyPoints(0);
	trap.beRepaired(10);
	trap.attack("Bar");
	trap.setEnergyPoints(100);
	trap.beRepaired(10);
	trap.attack("Bar");
	trap.takeDamage(12);
	trap.takeDamage(8);
	return (0);
}