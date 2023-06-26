/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:22:20 by franmart          #+#    #+#             */
/*   Updated: 2023/06/26 11:08:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog():Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
	std::cout << "Brain address: " << this->brain << std::endl;;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->type = copy.getType();
	this->brain = new Brain(*copy.brain);
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.getType();
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "[ Woof woof! ]" << std::endl;
}
