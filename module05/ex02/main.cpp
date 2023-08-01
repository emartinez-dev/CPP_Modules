/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:08:50 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 19:14:57 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main (void)
{
	Bureaucrat a(1, "Felipe");
	Bureaucrat b(20, "Manolo");
	Bureaucrat c(150, "Menganito");

	AForm *FormA = new ShrubberyCreationForm("home");
	AForm *FormB = new RobotomyRequestForm("Bender");
	AForm *FormC = new PresidentialPardonForm("Rick");
	
	std::cout << "Tested Bureaucrats _________________________________" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	std::cout << "\nTested forms _____________________________________" << std::endl;
	std::cout << *FormA << std::endl;
	std::cout << *FormB << std::endl;
	std::cout << *FormC << std::endl;
	
	std::cout << "\nException handling tests _________________________" << std::endl;
	std::cout << "\nNot enough level to sign:\n";
	c.signForm(*FormA);
	std::cout << "Sign form correctly:\n";
	b.signForm(*FormA);
	std::cout << "\nSign form twice:\n";
	b.signForm(*FormA);
	std::cout << "\nNot enough level to execute:\n";
	c.executeForm(*FormA);

	std::cout << "\nTest that all the forms work _____________________" << std::endl;
	std::cout << "\nSign remaining forms:\n";
	b.signForm(*FormB);
	a.signForm(*FormC);
	std::cout << "\nExecute the remaining forms:\n";

	b.executeForm(*FormA);
	std::cout << "\n";
	b.executeForm(*FormB);
	std::cout << "\n";
	a.executeForm(*FormC);
	std::cout << "\n";

	delete FormA;
	delete FormB;
	delete FormC;

	return 0;
}
