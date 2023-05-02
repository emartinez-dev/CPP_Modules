/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:31:08 by franmart          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:10 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdio.h>

int	main(void)
{
	Zombie *zb;

	zb = newZombie("Pantera");
	zb->announce();
	randomChump("Nano");
	delete zb;
	return (0);
}