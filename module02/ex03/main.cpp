/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:15:15 by franmart          #+#    #+#             */
/*   Updated: 2023/05/19 13:39:04 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

/* Tool to represent points online: https://www.geogebra.org/graphing */

int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.5f, 2.5f);
	Point	point(1.0f, 0.5f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "a) x:" << a.getX() << " y:" << a.getY() << std::endl;
	std::cout << "b) x:" << b.getX() << " y:" << b.getY() << std::endl;
	std::cout << "c) x:" << c.getX() << " y:" << c.getY() << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "\nPoint x:" << point.getX() << " y:" << point.getY() \
			<< " is inside the triangle" << std::endl;
	else
		std::cout << "\nPoint x:" << point.getX() << " y:" << point.getY() \
			<< " is outside the triangle" << std::endl;
	return 0;
}