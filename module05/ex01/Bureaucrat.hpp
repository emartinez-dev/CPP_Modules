/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:32:42 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 11:45:34 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int				  _grade;
	public:
		Bureaucrat();
		Bureaucrat(int grade, const std::string &name);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat	&operator=(Bureaucrat const &copy);

		std::string getName(void) const;
		int			getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		void		signForm(Form &F);
		class		GradeTooHighException;
		class		GradeTooLowException;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif

