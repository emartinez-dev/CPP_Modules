/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:06:44 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 13:26:52 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::c = 0;
int ScalarConverter::i = 0;
float ScalarConverter::f = 0.0f;
double ScalarConverter::d = 0.0;
char ScalarConverter::type = 'e';

int		ScalarConverter::c_err = 0;
int		ScalarConverter::i_err = 0;
int		ScalarConverter::f_err = 0;
int		ScalarConverter::d_err = 0;

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
	else if (!literal.compare("+inf") || !literal.compare("-inf") || !literal.compare("nan"))
	{
		type = 'd';
		ScalarConverter::i_err = 1;
		ScalarConverter::c_err = 1;
	}
	else if (!literal.compare("+inff") || !literal.compare("-inff") || !literal.compare("nanf"))
	{
		type = 'f';
		ScalarConverter::i_err = 1;
		ScalarConverter::c_err = 1;
	}
	else if (literal.find(".") == no && is_number(literal))
		type = 'i';
	else if (literal.find("f") == no && literal.find(".") != no)
		type = 'd';
	else if (literal.find("f") == literal.length() - 1 && literal.find(".") != no)
		type = 'f';
	else
		type = 'e';
	return type;
}

void  ScalarConverter::convert(std::string const &literal)
{
	char c = getType(literal);	
	ScalarConverter::type = c;
	long int temp = strtol(literal.c_str(), NULL, 10);

	switch (c)
	{
		case 'c':	
			ScalarConverter::c = literal.at(0);
			ScalarConverter::i = static_cast<int>(ScalarConverter::c);
			ScalarConverter::d = static_cast<double>(ScalarConverter::c);
			ScalarConverter::f = static_cast<float>(ScalarConverter::c);
			break;
		case 'f':
			errno = 0;
			ScalarConverter::f = strtof(literal.c_str(), NULL);
			if (errno == ERANGE || ScalarConverter::f == HUGE_VALF || ScalarConverter::f == -HUGE_VALF)
				ScalarConverter::f_err = 1;
			ScalarConverter::c = static_cast<char>(ScalarConverter::f);
			ScalarConverter::d = static_cast<double>(ScalarConverter::f);
			ScalarConverter::i = static_cast<int>(ScalarConverter::f);
			break;
		case 'i':
			if (temp > INT_MAX || temp < INT_MIN)
				ScalarConverter::i_err = 1;
			ScalarConverter::i = temp;
			ScalarConverter::c = static_cast<char>(ScalarConverter::i);
			ScalarConverter::d = static_cast<double>(ScalarConverter::i);
			ScalarConverter::f = static_cast<float>(ScalarConverter::i);
			break;
		case 'd':
			errno = 0;
			ScalarConverter::d = strtod(literal.c_str(), NULL);
			if (errno == ERANGE || ScalarConverter::d == DBL_MAX || ScalarConverter::d == DBL_MIN)
				ScalarConverter::d_err = 1;
			ScalarConverter::c = static_cast<char>(ScalarConverter::d);
			ScalarConverter::i = static_cast<int>(ScalarConverter::d);
			ScalarConverter::f = static_cast<float>(ScalarConverter::d);
			break;
	}
	ScalarConverter::checkErrors();
	ScalarConverter::printResults();
}

void ScalarConverter::checkErrors(void)
{
	if (ScalarConverter::d < -128 || ScalarConverter::d > 127 || ScalarConverter::i < -128 \
		|| ScalarConverter::i > 127 || ScalarConverter::f < -128 || ScalarConverter::f > 127)
		ScalarConverter::c_err = 1;
	if (ScalarConverter::type == 'i' && ScalarConverter::i_err)
	{
		ScalarConverter::d_err = 1;
		ScalarConverter::f_err = 1;
		ScalarConverter::c_err = 1;
	}
 	if (ScalarConverter::type == 'f')
	{
		if (ScalarConverter::f <= static_cast<float>(std::numeric_limits<int>::min()) || \
			ScalarConverter::f >= static_cast<float>(std::numeric_limits<int>::max()))
			ScalarConverter::i_err = 1;
		if (ScalarConverter::f_err)
		{
			ScalarConverter::d_err = 1;
			ScalarConverter::i_err = 1;
			ScalarConverter::c_err = 1;
		}
	}
	if (ScalarConverter::type == 'd')
	{
		if (ScalarConverter::d < static_cast<double>(std::numeric_limits<int>::min()) \
			|| ScalarConverter::d > static_cast<double>(std::numeric_limits<int>::max()))
			ScalarConverter::i_err = 1;
		if (ScalarConverter::d_err)
		{
			ScalarConverter::f_err = 1;
			ScalarConverter::i_err = 1;
			ScalarConverter::c_err = 1;
		}
	}
}

void ScalarConverter::printResults(void)
{
	if (ScalarConverter::c_err || ScalarConverter::type == 'e')
		std::cout << "char: impossible" << std::endl;
	else if (ScalarConverter::c > 31 && ScalarConverter::c < 127)
		std::cout << "char: '" << ScalarConverter::c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (ScalarConverter::i_err || ScalarConverter::type == 'e')
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << ScalarConverter::i << std::endl;
	if (ScalarConverter::f_err || ScalarConverter::type == 'e')
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << "float: ";
		if (ScalarConverter::f - static_cast<int>(ScalarConverter::f) == 0)
			std::cout << ScalarConverter::f << ".0f" << std::endl;
		else
			std::cout << ScalarConverter::f << "f" << std::endl;
	}
	if (ScalarConverter::d_err || ScalarConverter::type == 'e')
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << "double: ";
		if (ScalarConverter::d - static_cast<int>(ScalarConverter::d) == 0)
			std::cout << ScalarConverter::d << ".0" << std::endl;
		else
			std::cout << ScalarConverter::d << std::endl;
	}
}

bool is_number(std::string const &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		else if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

