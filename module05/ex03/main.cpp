/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:08:50 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 10:11:44 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main (void)
{
	Intern someRandomIntern;
	AForm	*rrf;
	Bureaucrat a(143, "Homer");
	Bureaucrat b(1, "Lenny");

	std::cout << "Testing PresidentialPardonForm_________________\n" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Bart"); 
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;

	std::cout << "\nTesting ShrubberyCreationForm________________\n" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "home"); 
	a.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;

	std::cout << "\nTesting RobotomyRequestForm__________________\n" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender"); 
	b.signForm(*rrf);
	b.executeForm(*rrf);
	delete rrf;

	std::cout << "\nTesting Unknown Form_________________________\n" << std::endl;
	rrf = someRandomIntern.makeForm("robotomization request", "Bender"); 
	if (rrf)
	{
		a.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	}
	return 0;
}
