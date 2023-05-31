/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:19:08 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:19:50 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <cstddef>

class Character: public ICharacter
{
	private:
		std::string	name;
		int			equiped;
		AMateria 	*slots[4];
	public:
		Character();
		Character(std::string const& name);
		Character(Character const &copy);
		~Character();
		Character	&operator=(Character const &copy);

		std::string const &getName() const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
