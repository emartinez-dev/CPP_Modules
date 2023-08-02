/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:06:44 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 12:58:53 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <exception>

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
	if (this != &copy)
		*this = copy;
	return *this;
}

void  ScalarConverter::convert(std::string const &literal)
{
	try 
	{
		char c = toChar(literal);
		if (c > 31 && c < 127)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
	}	
	try
	{
		toInt(literal);
	}
	catch (std::exception &e)
	{
		std::cout << "int: impossible" << std::endl;
	}
	try
	{
		toFloat(literal);

	}
	catch (std::exception &e)
	{
		std::cout << "float: impossible" << std::endl;
	}
	try
	{
		toDouble(literal);
	}
	catch (std::exception &e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}


char	ScalarConverter::toChar(std::string const &literal)
{
	if (literal.length() == 1 && !isdigit(literal.at(0)))
		return literal.at(0);
	int	i = std::stoi(literal);
	if (i <= 127 && i >= 0)
		return (static_cast<char>(i));
	throw std::exception();
}

int		ScalarConverter::toInt(std::string const &literal)
{
	int	i = std::stoi(literal);

	std::cout << "int: " << i << std::endl;
	return i;
}

float	ScalarConverter::toFloat(std::string const &literal)
{
	float f = std::stof(literal);

	if (f - static_cast<int>(f) != 0.0)
		std::cout << "float: " << f << "f"<< std::endl;
	else
		std::cout << "float: " << f << ".0f"<< std::endl;
	return f;
}

double  ScalarConverter::toDouble(std::string const &literal)
{
	double d = std::stod(literal);

	if (d - static_cast<int>(d) != 0.0)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0"<< std::endl;
	return d;
}

