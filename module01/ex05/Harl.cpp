/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:13:56 by franmart          #+#    #+#             */
/*   Updated: 2023/05/05 13:34:05 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}


Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << STR_DEBUG << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << STR_INFO << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << STR_WARNING << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << STR_ERROR << std::endl << std::endl;
}

/* In this function we create an array of function pointers called f. The syntax
to create it is:
	< return_type (Class::*function_ptr_name[n_of_functions])( params ) >

We can also create only one function pointer, in that case we remove the n of
functions.

The next step is to save the desired functions in the array, but we could also
do it with brackets as a normal constant array.
			< function_ptr_name[index] = &Class::function >

Last step, to call them, we use the following syntax:
			< (this->*function_ptr_name[index])( params ) > */

void	Harl::complain(std::string level)
{
	std::string	levels_cmp;
	int			level_type;
	void 		(Harl::*f[4])(void);

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;

	levels_cmp = "[DEBUG][INFO][WARNING][ERROR]";
	level.insert(0, "[");
	level.insert(level.length(), "]");
	level_type = levels_cmp.find(level);
	switch (level_type) {
		case TYPE_DEBUG:
			(this->*f[0])();
			break;
		case TYPE_INFO:
			(this->*f[1])();
			break;
		case TYPE_WARNING:
			(this->*f[2])();
			break;
		case TYPE_ERROR:
			(this->*f[3])();
			break;
	}
}
