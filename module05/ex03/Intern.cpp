/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:43:48 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 10:12:01 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(Intern const &copy)
{
	(void) copy;
}

Intern	&Intern::operator=(const Intern &copy)
{
	(void) copy;
	return *this;
}

AForm *Intern::makeForm(const std::string &type, const std::string &target)
{
	AForm *ptr = NULL;
	std::string form_list = "[robotomy request][shrubbery creation][presidential pardon]";
	std::string lower_type = "";

	for (size_t i = 0; i < type.length(); i++)
		lower_type += tolower(type.at(i));
	std::string input = "[" + lower_type + "]";
	int	index = form_list.find(input, 0);
	switch (index)
	{
		case -1:
			std::cout << "Form type <" << type << "> is not a known form\n";
			break;
		case 0:
			ptr = new RobotomyRequestForm(target);
			break;
		case 18:
			ptr = new ShrubberyCreationForm(target);
			break;
		case 38:
			ptr = new PresidentialPardonForm(target);
			break;
	}
	return ptr;
}

