/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:38:34 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 18:06:55 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):\
	AForm("Robotomy Request Form", 72, 45, target)
{
}


RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):AForm(copy)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		*this = copy;
	}
	return *this;
}

/* We have to seed the random number generator, if we don't do it the seed is always 1
 * and it generates the same random numbers */

void  RobotomyRequestForm::doExecute(void) const
{
	int	random_n;

	std::srand(std::time(0));
	random_n = std::rand() % 2;
	std::cout << "** Drill noises **" << std::endl;
	if (random_n)
		std::cout << this->getTarget() << " has been robotomized succesfully" << std::endl;
	else
		std::cout << "There has been a problem robotomizing " << this->getTarget() << std::endl;
}
