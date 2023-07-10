/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:48:05 by franmart          #+#    #+#             */
/*   Updated: 2023/07/10 09:46:30 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

/* ClapTrap attributes are now protected, so they are accesible from the class
that defines them and classes that inherit from that class. If they were private
they would only be accesible from itself */

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string const &name);
		~ClapTrap();
		ClapTrap(ClapTrap const &copy);
		ClapTrap	&operator=(ClapTrap const &copy);
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	setHitPoints(unsigned int amount);
		void	setEnergyPoints(unsigned int amount);
		void	setAttackDamage(unsigned int amount);
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		std::string		getName() const;
};

#endif
