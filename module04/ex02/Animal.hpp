/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:12:10 by franmart          #+#    #+#             */
/*   Updated: 2023/07/13 10:49:34 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* To not allow a class to be instantiable, we just need to put all the 
constructors as protected */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
		Animal();
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &copy);
	public:
		virtual ~Animal();
		std::string	getType() const;
		virtual void	makeSound() const = 0;
};

#endif
