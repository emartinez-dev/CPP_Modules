/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:08:50 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 11:52:18 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main (void) {
	
	Bureaucrat a(1, "Felipe");
	Bureaucrat b(20, "Manolo");
	Bureaucrat c(150, "Menganito");

	Form formA("FormA", 120, 120);
	Form formB("FormB", 1, 1);

	std::cout << "Form signing tests_________________\n" << std::endl;
	std::cout << "----- Sign higher grade form ----\n" << std::endl;
	std::cout << "Form: " << formA;
	std::cout << "Bureaucrat: " << c << std::endl;
	c.signForm(formA);
	std::cout << "Form after sign: " << formA;
	

	std::cout << "\n---- Sign lower grade form ----\n" << std::endl;
	std::cout << "Form: " << formA;
	std::cout << "Bureaucrat: " << b << std::endl;
	b.signForm(formA);
	std::cout << "Form after sign: " << formA;

	std::cout << "\n---- Sign already signed form ----\n" << std::endl;
	std::cout << "Form: " << formA;
	std::cout << "Bureaucrat: " << b << std::endl;
	b.signForm(formA);
	std::cout << "Form after sign: " << formA;

	std::cout << "\n---- Sign equal grade form ----\n" << std::endl;
	std::cout << "Form: " << formB;
	std::cout << "Bureaucrat: " << a << std::endl;
	a.signForm(formB);
	std::cout << "Form after sign: " << formB;

	std::cout << "\n\nForm errors tests_________________\n" << std::endl;
	std::cout << "Creating form lower than grade 150: " << std::endl;
	try
	{
		Form formC("FormC", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}
	std::cout << "Creating form higher than grade 1: " << std::endl;
	try
	{
		Form formD("FormD", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	return 0;
}
