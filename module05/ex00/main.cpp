/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:12:36 by franmart          #+#    #+#             */
/*   Updated: 2023/07/31 18:19:22 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main (void)
{
	Bureaucrat a(1, "Felipe");
	Bureaucrat b(20, "Manolo");
	Bureaucrat c(150, "Menganito");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	b.incrementGrade();
	std::cout << b << std::endl;
	b.decrementGrade();
	std::cout << b << std::endl;

	try 
	{
		a.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	try 
	{
		c.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;	
	}
	
	try
	{
		Bureaucrat high(0, "Error");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	try
	{
		Bureaucrat low(191, "Error");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	return 0;
}
