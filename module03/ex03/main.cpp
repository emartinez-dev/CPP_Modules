/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:14:52 by franmart          #+#    #+#             */
/*   Updated: 2023/05/22 16:14:33 by franmart         ###   ########.fr       */
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
	return (0);
}