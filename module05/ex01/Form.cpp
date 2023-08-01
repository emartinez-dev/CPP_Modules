/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:27:01 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 11:49:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

class Form::GradeTooHighException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<GradeTooHighException> Grade must be greater or equal than 1\n");
	}
};

class Form::GradeTooLowException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<GradeTooLowException> Grade must be lower or equal than 150\n");
	}
};



Form::Form():_name("Unnamed form"),_signed(false),_grade_sign(1),_grade_execute(1)
{
}

Form::Form(const std::string &name, const int grade_sign, \
			const int grade_execute):
	_name(name),_signed(false),_grade_sign(grade_sign),_grade_execute(grade_execute)
{
	if (this->getGradeSign() < 1 || this->getGradeExecute() < 1)
		throw GradeTooHighException();
	else if (this->getGradeSign() > 150 || this->getGradeExecute() > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(Form const &copy):_name(copy._name),_signed(copy._signed),\
	_grade_sign(copy._grade_sign),_grade_execute(copy._grade_execute)
{
}

Form	&Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		std::cout << "Can't assign name with operator = because it is constant" \
			<< std::endl;
		_signed = copy._signed;
		std::cout << "Can't assign grades with operator = because they are constant" \
			<< std::endl;
	}
	return *this;
}

std::string	  Form::getName(void) const
{
	return this->_name;
}

bool		  Form::getIsSigned(void) const
{
	return this->_signed;
}

int			  Form::getGradeSign(void) const
{
	return this->_grade_sign;
}

int			  Form::getGradeExecute(void) const
{
	return this->_grade_execute;
}

void		  Form::beSigned(Bureaucrat &B)
{
	if (B.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form name " << obj.getName()	<< ", grade required to sign: " << \
		obj.getGradeSign() << ", grade required to execute: " << obj.getGradeExecute();
	if (obj.getIsSigned())
		os << " -> \033[92mSIGNED\033[0m" << std::endl;
	else
		os << " -> \033[93mNot signed\033[0m" << std::endl;
	return os;
}

