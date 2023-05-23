/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:31:24 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 15:43:44 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain	&Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &copy)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	return (*this);
}