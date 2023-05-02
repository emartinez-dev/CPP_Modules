/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:15:38 by franmart          #+#    #+#             */
/*   Updated: 2023/05/02 10:25:42 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		~Zombie();
		void	announce( void );
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif