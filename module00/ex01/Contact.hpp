/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:59:29 by franmart          #+#    #+#             */
/*   Updated: 2023/04/24 10:53:39 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>

# define STR_FIRSTNAME "First name: "
# define STR_LASTNAME "Last name: "
# define STR_NICKNAME "Nickname: "
# define STR_PHONE "Phone number: "
# define STR_SECRET "Darkest secret: "

class Contact
{
	private:
		int			_id;
		std::string _fname;
		std::string _lname;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
		std::string	_get_input(std::string message);
	public:
		Contact();
		~Contact();
		void	add();
		void	display();
};

#endif