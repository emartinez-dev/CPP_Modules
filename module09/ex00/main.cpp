/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:57:13 by franmart          #+#    #+#             */
/*   Updated: 2023/08/29 17:21:05 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments. Usage: ./btc [input_file]\n";
		return (1);
	}
	BitcoinExchange exchange;
	calculateExchange(argv[1], &exchange);
	return 0;
}
