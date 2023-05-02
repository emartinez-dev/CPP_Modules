/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:31:08 by franmart          #+#    #+#             */
/*   Updated: 2023/05/02 15:44:39 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "String address    = " << &str << std::endl;
	std::cout << "StringPTR address = " << &(*stringPTR) << std::endl;
	std::cout << "StringREF address = " << &stringREF << std::endl << std::endl;

	std::cout << "String value    = " << str << std::endl;
	std::cout << "StringPTR value = " << *stringPTR << std::endl;
	std::cout << "StringREF value = " << stringREF << std::endl;

	return (0);
}
