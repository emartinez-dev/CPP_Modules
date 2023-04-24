/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:57:44 by franmart          #+#    #+#             */
/*   Updated: 2023/04/24 15:06:20 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_last_id = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::display_list()
{
	if (this->_last_id > 0)
	{
		std::cout << "|    ID    |First name| Last name| Nickname |" << \
			std::endl;
		for (int i = 1; i < 8; i++)
			this->_contacts[i].display_compact();
		this->_contacts[0].display_compact();
		std::cout << std::endl;
	}
}

void	PhoneBook::add_contact()
{
	this->_last_id++;
	this->_contacts[this->_last_id % 8].add();
	this->_contacts[this->_last_id % 8].id = this->_last_id;
}

void	PhoneBook::display_menu()
{
	std::cout 	<< "_____________________" << std::endl\
				<< "                     " << std::endl\
				<< "      Phonebook      " << std::endl\
				<< "        Menu         " << std::endl\
				<< "_____________________" << std::endl\
				<< "                     " << std::endl\
				<< "   Valid commands:   " << std::endl\
				<< "  ADD, SEARCH, EXIT  " << std::endl\
				<< "_____________________" << std::endl\
				<< "Enter a command: ";
}

void	PhoneBook::search()
{
	std::string		str;
	unsigned int	i;

	this->display_list();
	if (this->_last_id > 0)
	{
		std::cout << "Select a contact ID to display:" << std::endl;
		std::getline(std::cin, str);
		i = atoi(str.c_str());
		if (i > 0 && i <= this->_last_id)
		{
			if (i == this->_contacts[i % 8].id)
			{
				this->_contacts[i % 8].display_full();
				return ;
			}
		}
		system("clear");
		std::cout << "Contact ID is not valid." << std::endl;
	}
	else
	{
		system("clear");
		std::cout << "Nothing to see here. Contact list is empty." << std::endl;
	}
}