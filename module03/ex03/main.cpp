/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:14:52 by franmart          #+#    #+#             */
/*   Updated: 2023/06/25 15:16:00 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include <ostream>

int	main(void)
{
	DiamondTrap	trap("Foo");

	trap.getAttackDamage();
	trap.attack("Bar");
	trap.whoAmI();
	trap.guardGate();
	trap.highFivesGuys();
	return (0);
}