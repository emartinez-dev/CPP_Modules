/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:21:54 by franmart          #+#    #+#             */
/*   Updated: 2023/06/26 11:08:28 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		~Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &copy);
		void makeSound(void) const;
};

#endif
