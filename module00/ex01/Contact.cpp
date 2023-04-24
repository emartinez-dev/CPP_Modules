/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:14:09 by franmart          #+#    #+#             */
/*   Updated: 2023/04/24 15:05:58 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->id = 0;
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
			std::cout << "-- Invalid input, please try again --" << std::endl;
		}
	}
	return (str);
}

void	Contact::add()
{
	this->_fname = _get_input(STR_FIRSTNAME);
	this->_lname = _get_input(STR_LASTNAME);
	this->_nickname = _get_input(STR_NICKNAME);
	this->_phone = _get_input(STR_PHONE);
	this->_secret = _get_input(STR_SECRET);
	system("clear");
	std::cout << "Contact added succesfully." << std::endl;
}

void	Contact::display_full()
{
	system("clear");
	std::cout << "- Contact info ----------------" << std::endl;
	std::cout << STR_FIRSTNAME << this->_fname << std::endl;
	std::cout << STR_LASTNAME << this->_lname << std::endl;
	std::cout << STR_NICKNAME << this->_nickname << std::endl;
	std::cout << STR_PHONE << this->_phone << std::endl;
	std::cout << STR_SECRET << this->_secret << std::endl;
}

void	Contact::display_compact()
{
	if (this->id == 0)
		return ;
	std::cout << "|" << std::string(10 - uint_len(this->id), ' ') << this->id;
	std::cout << "|" << trim_len(this->_fname);
	std::cout << "|" << trim_len(this->_lname);
	std::cout << "|" << trim_len(this->_nickname) << "|\n";
}

std::string trim_len(std::string str)
{
	if (str.length() > 9)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

int	uint_len(unsigned int i)
{
	int	len;

	len = 0;
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}
