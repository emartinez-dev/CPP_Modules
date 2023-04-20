/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:14:09 by franmart          #+#    #+#             */
/*   Updated: 2023/04/24 10:53:22 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::_get_input(std::string message)
{
	bool		valid = false;
	std::string	str = "";

	while (!valid)
	{
		std::cout << message << "\n> ";
		std::getline(std::cin, str);
		if (!str.empty())
			valid = true;
		else
		{
			std::cin.clear();
			std::cout << "-- Invalid input, please try again. --" << std::endl;
		}
	}
	return (str);
}

void	Contact::add()
{
	this->_id = 0;
	this->_fname = _get_input(STR_FIRSTNAME);
	this->_lname = _get_input(STR_LASTNAME);
	this->_nickname = _get_input(STR_NICKNAME);
	this->_phone = _get_input(STR_PHONE);
	this->_secret = _get_input(STR_SECRET);
}

void	Contact::display()
{
	std::cout << "----- Contact info ------" << std::endl;
	std::cout << STR_FIRSTNAME << this->_fname << std::endl;
	std::cout << STR_LASTNAME << this->_lname << std::endl;
	std::cout << STR_NICKNAME << this->_nickname << std::endl;
	std::cout << STR_PHONE << this->_phone << std::endl;
	std::cout << STR_SECRET << this->_secret << std::endl;
	std::cout << "-------------------------" << std::endl;
}
