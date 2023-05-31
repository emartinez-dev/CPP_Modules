/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:26:14 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:21:05 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASORUCE_HPP
#define MATERIASORUCE_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*slots[4];
		int			learnt;

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource	&operator=(MateriaSource const &copy);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
