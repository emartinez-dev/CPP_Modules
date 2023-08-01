/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:26:33 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 11:42:46 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool			  _signed;
		const int		  _grade_sign;
		const int		  _grade_execute;

	public:
		Form();
		Form(const std::string &name, const int grade_sign, \
			const int grade_execute);
		~Form();
		Form(Form const &copy);
		Form	&operator=(Form const &copy);

		std::string	  getName(void) const;
		bool		  getIsSigned(void) const;
		int			  getGradeSign(void) const;
		int			  getGradeExecute(void) const;

		void		  beSigned(Bureaucrat &B);

		class		GradeTooHighException;
		class		GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
