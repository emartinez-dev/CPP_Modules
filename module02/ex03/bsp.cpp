/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:03:55 by franmart          #+#    #+#             */
/*   Updated: 2023/05/18 18:30:46 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <cmath>

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	list[3];
	Fixed	minX(MAXFLOAT);
	Fixed	maxX(INFINITY);
	Fixed	minY(MAXFLOAT);
	Fixed	maxY(INFINITY);
	Fixed	pointX;
	Fixed	pointY;

	list[0] = a;
	list[1] = b;
	list[2] = c;
	for (int i = 0; i < 3; i++)
	{
		minX = Fixed::min(list[i].getX(), minX);
		minY = Fixed::min(list[i].getY(), minY);
		maxX = Fixed::max(list[i].getX(), maxX);
		maxY = Fixed::max(list[i].getY(), maxY);
	}
	pointX = point.getX();
	pointY = point.getY();
	if (pointX < minX || pointX > maxX || pointY < minY || pointY > maxY)
		return false;
	return true;
}
