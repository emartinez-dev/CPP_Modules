/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:29:52 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 11:31:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat: public Animal
{
	private:

	public:
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &copy);
};

#endif

