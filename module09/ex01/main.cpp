/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:59:10 by franmart          #+#    #+#             */
/*   Updated: 2023/08/30 12:56:55 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of parameters. Usage: ./RPN "\
			"[1 digit operands space separated]\n";
		return (0);
	}
	RPN calculator;

	calculator.operate(std::string(argv[1]));
	int	result = calculator.getResult();
	if (!calculator.checkError())
		std::cout << result << std::endl;
	calculator.printError();
	return (0);
}

