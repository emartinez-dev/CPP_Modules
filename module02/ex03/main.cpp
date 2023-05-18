/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:15:15 by franmart          #+#    #+#             */
/*   Updated: 2023/05/18 18:15:11 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.5f, 2.5f);
	Point	check_true(1.0f, 1.0f);
	Point	check_false(12.0f, 12.0f);
	bool	bsp_true;
	bool	bsp_false;

	bsp_true = bsp(a, b, c, check_true);
	if (bsp_true)
		std::cout << "The point <check_true> is inside the triangle formed by"\
			" a, b and c" << std::endl;
	bsp_false = bsp(a, b, c, check_false);
	if (!bsp_false)
		std::cout << "The point <check_false> is outside the triangle formed by"\
			" a, b and c" << std::endl;
	return 0;
}