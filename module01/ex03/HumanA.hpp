/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:15:38 by franmart          #+#    #+#             */
/*   Updated: 2023/05/08 10:34:57 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

/* Here we use references for the weapon of the human A, but we could use a pointer
too. The only difference I have found is that references can't be NULL and
pointers can be, so its generally safer but it can cause trouble when copying.
There is a lot of debate about this matter:
https://stackoverflow.com/questions/1974682/using-reference-as-class-members-for-dependencies
*/

class HumanA
{
        private:
		std::string	_name;
		Weapon		&_weapon;
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA();
		void	setWeapon(Weapon &weapon);
		void	attack( void );
};

#endif
