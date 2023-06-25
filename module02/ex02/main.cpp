/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:15:15 by franmart          #+#    #+#             */
/*   Updated: 2023/06/25 14:55:02 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a(2);
	Fixed b(Fixed(5.05f) * Fixed(2));

	std::cout << "A: " << a << std::endl;
	std::cout << "A bit previous increase: " << ++a << std::endl;
	std::cout << "A updated: " << a << std::endl;
	std::cout << "A bit post increase: " << a++ << std::endl;
	std::cout << "A updated: " << a << std::endl << std::endl;
	std::cout << "A: "<< a << " | B: " << b << std::endl;
	std::cout << "A + B: " << a + b << std::endl;
	std::cout << "A - B: " << a - b << std::endl;
	std::cout << "A * B: " << a * b << std::endl;
	std::cout << "A / B: " << a / b << std::endl << std::endl;

	a = 0.4f;
	b = 0.5f;
	std::cout << "A: "<< a << " | B: " << b << std::endl;
	if (a > b)
		std::cout << "A is bigger than B" << std::endl;
	if (a < b)
		std::cout << "A is smaller than B" << std::endl;

	a = 0.5f;
	b = 0.5f;
	std::cout << "A: "<< a << " | B: " << b << std::endl;
	if (a >= b)
		std::cout << "A is bigger or equal to B" << std::endl;
	if (a <= b)
		std::cout << "A is smaller or equal to B" << std::endl;

	if (a == b)
		std::cout << "A is equal to B" << std::endl;
	if (a != b)
		std::cout << "A is not equal to B" << std::endl;

	a = 206.5f;
	b = 12.5f;
	std::cout << "A: "<< a << " | B: " << b << std::endl;
	std::cout << "Max between A and B: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min between A and B: " << Fixed::min(a, b) << std::endl;

	return 0;
}