/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:22:20 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 11:30:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}
