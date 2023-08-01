/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:43:23 by franmart          #+#    #+#             */
/*   Updated: 2023/08/01 19:45:06 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include <iostream>

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(Intern const &copy);
		Intern	&operator=(Intern const &copy);
		AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
