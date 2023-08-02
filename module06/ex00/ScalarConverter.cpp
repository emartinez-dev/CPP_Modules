/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:06:44 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 16:29:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <_ctype.h>
#include <exception>
#include <string>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	(void) copy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return *this;
}

char ScalarConverter::getType(std::string const &literal)
{
	size_t no = std::string::npos;
	char type;

	if (literal.length() == 1 && !isdigit(literal.at(0)))
		type = 'c';
	else if (literal.find(".") == no)
		type = 'i';
	else
		type = 'e';
	return type;
}

void  ScalarConverter::convert(std::string const &literal)
{
	char c = getType(literal);	

	switch (c)
	{
		case 'c':	
			std::cout << "char" << std::endl;
			break;
		case 'f':
			std::cout << "float" << std::endl;
			break;
		case 'i':
			std::cout << "int" << std::endl;
			break;
		case 'd':
			std::cout << "double" << std::endl;
			break;
	}
}

