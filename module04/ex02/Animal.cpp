/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:13:52 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 16:01:41 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal copy constructor" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
}

Animal	&Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.getType();
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	if (this->getType() == "Animal")
		std::cout << "[ Unrecognized animal sound ]" << std::endl;
	if (this->getType() == "Dog")
		std::cout << "[ Woof woof! ]" << std::endl;
	if (this->getType() == "Cat")
		std::cout << "[ Meooooooooow ]" << std::endl;
}
