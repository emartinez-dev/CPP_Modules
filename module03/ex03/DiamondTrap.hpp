/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:21:09 by franmart          #+#    #+#             */
/*   Updated: 2023/07/10 09:42:55 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

/* this exercise is a trap itself >:(
 * https://en.wikipedia.org/wiki/Multiple_inheritance

When we inherit from 2 classes and they both inherit from the same class, the
variables overlap each other if they have the same name, so we can't have 
ScavTrap energy and FragTrap energy, they overlap to the value of the most
recently inherited
*/

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap	&operator=(DiamondTrap const &copy);
		void	whoAmI();
};

#endif
