/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:26:33 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 18:52:58 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool			  _signed;
		const int		  _grade_sign;
		const int		  _grade_execute;
		std::string		  _target;
	public:
		AForm();
		AForm(const std::string &name, const int grade_sign, \
			const int grade_execute, const std::string &target);
		virtual ~AForm() = 0;
		AForm(AForm const &copy);
		AForm	&operator=(AForm const &copy);

		std::string	  getName(void) const;
		bool		  getIsSigned(void) const;
		int			  getGradeSign(void) const;
		int			  getGradeExecute(void) const;
		std::string	  getTarget(void) const;

		void		  beSigned(Bureaucrat &B);
		void		  execute(Bureaucrat const &executor) const;
		virtual	void  doExecute(void) const = 0;

		class		GradeTooHighException;
		class		FormNotSigned;
		class		GradeTooLowException;
		class		NotEnoughGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif
