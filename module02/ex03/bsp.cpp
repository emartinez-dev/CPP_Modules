/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:03:55 by franmart          #+#    #+#             */
/*   Updated: 2023/05/19 13:36:54 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/* Different implementation: the triangles area method!
reference: https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle
*/

Fixed	triangle_area(Point const a, Point const b, Point const c)
{
	Point	ab(b.getX().toFloat() - a.getX().toFloat(), \
		b.getY().toFloat() - a.getY().toFloat());
	Point	ac(c.getX().toFloat() - a.getX().toFloat(), \
		c.getY().toFloat() - a.getY().toFloat());
	Fixed	area(((ab.getX() * ac.getY() - ab.getY() * ac.getX()) / Fixed(2.0f)).toFloat());
	if (area < 0)
		return (area * -1);
	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc(triangle_area(a, b, c));
	Fixed	area_sum(0.0f);

	area_sum = area_sum + triangle_area(a, b, point);
	area_sum = area_sum + triangle_area(a, c, point);
	area_sum = area_sum + triangle_area(b, c, point);
	return (area_sum == area_abc);
}
