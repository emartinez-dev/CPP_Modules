/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:16:01 by franmart          #+#    #+#             */
/*   Updated: 2023/08/23 15:17:20 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Span sp = Span(5);

	std::cout << "Testing the main on the subject ___________________________\n";
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\nTesting adding more numbers to a full span ________________\n";
	try {
		sp.addNumber(42);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nTesting calculating span with only one number _____________\n";
	try {
		Span sp2 = Span(1);
		sp2.addNumber(42);
		sp2.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\nGenerating a span with random values _____________________\n";
	srand(time(NULL));
	Span sp3 = Span(4);
	sp3.fillRandom();
	for (int i = 0; i < 4; i++)
		std::cout << "Elem " << i << ": -> " << sp3[i] << std::endl;

	std::cout << "\nShortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

	std::cout << "\nGenerating a span with 10.000 random values _____________\n";
	Span sp4 = Span(10000);
	sp4.fillRandom();
	std::cout << "\nShortest span: " << sp4.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp4.longestSpan() << std::endl;

	std::cout << "\nGenerating a span with 100.000 random values _____________\n";
	Span sp5 = Span(100000);
	sp5.fillRandom();
	std::cout << "\nShortest span: " << sp5.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp5.longestSpan() << std::endl;

	return 0;
}
