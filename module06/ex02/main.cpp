/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:09:44 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 17:36:04 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>
#include <ctime>
#include <stdlib.h>

int main (void)
{
	Base	*ptr;
	Base	*ref;

	srand(time(NULL));	
	for (int i = 0; i < 5; i++)
	{
		ptr = generate();
		std::cout << "---- Generated new object ----" << std::endl;
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}
	
	for (int i = 0; i < 5; i++)
	{
		ref = generate();
		std::cout << "---- Generated new object ----" << std::endl;
		identify(*ref);
		delete ref;
		std::cout << std::endl;
	}
	return 0;
}
