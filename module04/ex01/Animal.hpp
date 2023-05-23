/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:12:10 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 13:30:53 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Here setting the Animal destructor as virtual is the difference between
leaking and not */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &copy);
		std::string	getType() const;
		void		makeSound() const;
};

#endif
