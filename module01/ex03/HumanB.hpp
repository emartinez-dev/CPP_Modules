/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:15:38 by franmart          #+#    #+#             */
/*   Updated: 2023/05/08 10:35:49 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

/* Here we use a pointer to the weapon as HumanB can have a weapon or not, so
it can be NULL */

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB( std::string name );
		~HumanB();
		void	setWeapon(Weapon &weapon);
		void	attack( void );
};

#endif
