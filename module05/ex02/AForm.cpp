/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:27:01 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 18:56:06 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm::GradeTooHighException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<GradeTooHighException> Grade must be greater or equal than 1\n");
	}
};

class AForm::GradeTooLowException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<GradeTooLowException> Grade must be lower or equal than 150\n");
	}
};

class AForm::FormNotSigned: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<FormNotSigned> Form must be signed before executing\n");
	}
};

class AForm::NotEnoughGrade: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("<NotEnoughGrade> The Bureaucrat has not enough grade to do what you asked him\n");
	}
};



AForm::AForm():_name("Unnamed form"),_signed(false),_grade_sign(1),_grade_execute(1)
{
}

AForm::AForm(const std::string &name, const int grade_sign, const int grade_execute,\
				const std::string &target):_name(name),_signed(false),\
				_grade_sign(grade_sign),_grade_execute(grade_execute),_target(target)
{
	if (this->getGradeSign() < 1 || this->getGradeExecute() < 1)
		throw GradeTooHighException();
	else if (this->getGradeSign() > 150 || this->getGradeExecute() > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(AForm const &copy):_name(copy._name),_signed(copy._signed),\
	_grade_sign(copy._grade_sign),_grade_execute(copy._grade_execute)
{
}

AForm	&AForm::operator=(const AForm &copy)
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

std::string	  AForm::getName(void) const
{
	return this->_name;
}

bool  AForm::getIsSigned(void) const
{
	return this->_signed;
}

int	AForm::getGradeSign(void) const
{
	return this->_grade_sign;
}

int	AForm::getGradeExecute(void) const
{
	return this->_grade_execute;
}

std::string	  AForm::getTarget(void) const
{
	return this->_target;
}

void  AForm::beSigned(Bureaucrat &B)
{
	if (B.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

void  AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExecute())
		throw AForm::NotEnoughGrade();
	else if (!this->getIsSigned())
		throw AForm::FormNotSigned();	
	else
		doExecute();	
}


std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << obj.getName()	<< ", grade required to sign: " << \
		obj.getGradeSign() << ", grade required to execute: " << obj.getGradeExecute();
	if (obj.getIsSigned())
		os << " -> \033[92mSIGNED\033[0m" << std::endl;
	else
		os << " -> \033[93mNot signed\033[0m" << std::endl;
	return os;
}

