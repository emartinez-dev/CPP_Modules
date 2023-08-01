/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:49:08 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 11:51:03 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

/*	Creating a custom exception class
 *
 *	In C++ exception class already exists and we can use them as std::exception.
 *	In order to create a custom Exception, we create a class inheriting
 *	from the base exception class and we override its methods. The syntax is like:
 *
 *		  virtual const char *what() const throw()
 *
 *	virtual: the what() method can be overriden in derived classes and its catched as and
 *			std::exception
 *
 *	const char *what(): what() method returns a constant char array (c string)
 *
 *	throw(): C++98 standard, it means that the what() method will not throw any exceptions,
 *			  it's not necessary for modern C++ and you could simply use 'noexcept'	
 */

class Bureaucrat::GradeTooHighException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<GradeTooHighException> Grade must be greater or equal than 1\n");
	}
};

class Bureaucrat::GradeTooLowException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<GradeTooLowException> Grade must be lower or equal than 150\n");
	}
};

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(int grade, const std::string &name):_name(name),_grade(grade)
{
	if (this->getGrade() < 1)
		throw GradeTooHighException();
	else if (this->getGrade() > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy):_name(copy._name), _grade(copy._grade)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy) {
		std::cout << "Can't copy name with operator = because it is constant" << std::endl;
		this->_grade = copy.getGrade();
	}
	return *this;
}


std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void		Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}

void  Bureaucrat::signForm(Form &F)
{
	if (F.getIsSigned())
		std::cout << _name << " couldn't sign " << F.getName() << \
			" because it's already signed" << std::endl;
	else
	{
		try
		{
			F.beSigned(*this);
			std::cout << getName() << " signed " << F.getName() << std::endl;
		}
		catch (std::exception &low)
		{
			std::cout << _name << " couldn't sign " << F.getName() << \
			" because Bureaucrat grade is too low" << std::endl;
		}
	}
}

