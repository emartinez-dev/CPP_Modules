/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:21:54 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 11:30:49 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog: public Animal
{
	private:

	public:
		Dog();
		~Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &copy);
};

#endif
