/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:18:57 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:31:51 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource():learnt(0)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->learnt; i++)
		delete this->slots[i];
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	(void) copy;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	(void) copy;
	return (*this);
}


void MateriaSource::learnMateria(AMateria*m)
{
	if (this->learnt >= 4)
	{
		delete m;
		return ;
	}
	this->slots[this->learnt] = m;
	this->learnt++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->learnt; i++)
	{
		if (this->slots[i]->getType() == type)
			return (this->slots[i]->clone());
	}
	return 0;
}