/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:16:01 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 11:37:54 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters, one and only one needed" << std::endl;
		return 1;
	}
	std::string const str(argv[1]);
	ScalarConverter::convert(str);
	return 0;
}
