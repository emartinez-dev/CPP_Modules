/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:33:26 by franmart          #+#    #+#             */
/*   Updated: 2023/04/24 14:31:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	system("clear");
	while (1)
	{
		phonebook.display_menu();
		std::getline(std::cin, command);
		std::cout << std::endl;
		if (!command.compare("ADD"))
			phonebook.add_contact();
		else if (!command.compare("SEARCH"))
			phonebook.search();
		else if (!command.compare("EXIT"))
		{
			std::cout << "Goodbye!" << std::endl;
			return (0);
		}
		else
		{
			system("clear");
			std::cout << "Command not found: " << command << std::endl;
		}
	}
	return (0);
}