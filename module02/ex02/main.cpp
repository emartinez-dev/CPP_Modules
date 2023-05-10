/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:15:15 by franmart          #+#    #+#             */
/*   Updated: 2023/05/10 13:36:07 by franmart         ###   ########.fr       */
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
	if (a > b)
		std::cout << "A is bigger than B" << std::endl;
	if (b > a)
		std::cout << "B is bigger than A" << std::endl;

	std::cout << "Max between A and B: " << Fixed::max(a, b) << std::endl;

	return 0;
}