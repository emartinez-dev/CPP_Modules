/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:15:55 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:18:17 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::~Cure()
{
}

Cure::Cure(Cure const &copy)
{
	if (this != &copy)
		this->type = copy.getType();
}

Cure	&Cure::operator=(const Cure &copy)
{
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure();
}
