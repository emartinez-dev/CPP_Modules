/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:49:36 by franmart          #+#    #+#             */
/*   Updated: 2023/05/23 11:52:36 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

class WrongCat: public WrongAnimal
{
	private:

	public:
		WrongCat();
		~WrongCat();
		WrongCat(WrongCat const &copy);
		WrongCat	&operator=(WrongCat const &copy);
};

#endif

