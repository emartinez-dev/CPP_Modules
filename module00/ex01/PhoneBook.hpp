/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:54:07 by franmart          #+#    #+#             */
/*   Updated: 2023/04/24 15:04:05 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <stdlib.h>
# include <string.h>

class PhoneBook
{
	private:
		Contact			_contacts[8];
		unsigned int	_last_id;
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	display_list();
		void	search();
		void	display_menu();
};

#endif