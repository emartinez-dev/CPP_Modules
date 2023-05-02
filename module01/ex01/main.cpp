/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:31:08 by franmart          #+#    #+#             */
/*   Updated: 2023/05/02 12:51:58 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	ft_leaks(void)
{
	system("leaks moar_brainz");
}

int	main(void)
{
	Zombie *horde;
	int		n;

	n = 5;
	atexit(ft_leaks);
	horde = zombieHorde(n, "Johnny");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
