/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:08:50 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 18:57:40 by franmart         ###   ########.fr       */
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
	
	std::cout << *FormA << std::endl;
	std::cout << *FormB << std::endl;
	std::cout << *FormC << std::endl;
	
	a.signForm(*FormA);
	c.executeForm(*FormA);

	a.signForm(*FormB);
	c.executeForm(*FormB);

	a.signForm(*FormC);
	c.executeForm(*FormC);

	delete FormA;
	delete FormB;
	delete FormC;

	return 0;
}
