/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:12:05 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 12:17:54 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::~Ice()
{
}

Ice::Ice(Ice const &copy)
{
	if (this != &copy)
		this->type = copy.getType();
}

Ice	&Ice::operator=(const Ice &copy)
{
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice();
}
