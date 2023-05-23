/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:29:22 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 11:31:51 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat():Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}
