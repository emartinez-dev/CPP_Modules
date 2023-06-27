/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:15:15 by franmart          #+#    #+#             */
/*   Updated: 2023/06/27 12:02:34 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Tool to represent points online: https://www.geogebra.org/graphing */

int main(void)
{
	Point	a(0.0f, 0.0f);
	Point	b(5.0f, 0.0f);
	Point	c(2.5f, 2.5f);
	Point	inside(1.0f, 0.5f);
	Point	outside(0.0f, 0.0f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "a) x:" << a.getX() << " y:" << a.getY() << std::endl;
	std::cout << "b) x:" << b.getX() << " y:" << b.getY() << std::endl;
	std::cout << "c) x:" << c.getX() << " y:" << c.getY() << std::endl;
	if (bsp(a, b, c, inside))
		std::cout << "\nPoint x:" << inside.getX() << " y:" << inside.getY() \
			<< " is inside the triangle" << std::endl;
	else
		std::cout << "\nPoint x:" << inside.getX() << " y:" << inside.getY() \
			<< " is outside the triangle" << std::endl;

	if (bsp(a, b, c, outside))
		std::cout << "\nPoint x:" << outside.getX() << " y:" << outside.getY() \
			<< " is inside the triangle" << std::endl;
	else
		std::cout << "\nPoint x:" << outside.getX() << " y:" << outside.getY() \
			<< " is outside the triangle" << std::endl;

	return 0;
}
