/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:28:23 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 17:26:28 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):\
	AForm("Presidential Pardon Form", 25, 5, target)
{
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):\
	AForm(copy)
{
}

PresidentialPardonForm	\
	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

void  PresidentialPardonForm::doExecute(void) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

