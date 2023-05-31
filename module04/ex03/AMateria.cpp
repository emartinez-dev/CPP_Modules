/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:24 by franmart          #+#    #+#             */
/*   Updated: 2023/05/31 11:25:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type): type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const &copy)
{
	if (this != &copy)
		*this = copy;
}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}


std::string const &AMateria::getType() const
{
	return (this->type);
}
