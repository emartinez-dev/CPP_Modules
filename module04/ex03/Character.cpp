/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:29 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:47:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string const &name): name(name), equiped(0)
{
	for (int i = 0; i < 4; i++)
		this->slots[i] = nullptr;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->slots[i];
}

Character::Character(Character const &copy): name(copy.getName()), equiped(0)
{
	for (int i = 0; i < copy.equiped; i++)
		this->equip(copy.slots[i]->clone());
	for (int i = this->equiped; i < 4; i++)
		this->slots[i] = nullptr;
}

Character	&Character::operator=(const Character &copy)
{
	if (this == &copy)
		return (*this);
	this->name = copy.getName();
	for (int i = 0; i < this->equiped; i++)
		delete this->slots[i];
	for (int i = 0; i < copy.equiped; i++)
		this->equip(copy.slots[i]->clone());
	for (int i = this->equiped; i < 4; i++)
		this->slots[i] = nullptr;
	return (*this);
}


std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria *m)
{
	if (this->equiped >= 4)
		return ;
	this->slots[this->equiped] = m;
	this->equiped++;
}

/* I have decided to delete AMaterias in the moment they get unequiped, as they
are skills that a Character can use and not items that can drop on the floor. */

void Character::unequip(int idx)
{
	if (idx < 0 || this->equiped <= idx)
		return ;
	for (int i = idx; i < 3; i++)
	{
		delete this->slots[i];
		this->slots[i] = this->slots[i + 1];
		this->slots[i + 1] = nullptr;
	}
	this->equiped--;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || this->equiped <= idx || this->slots[idx] == nullptr)
	{
		std::cout << "You haven't equiped anything in this slot, so can't use!\n";
		return ;
	}
	this->slots[idx]->use(target);
}
