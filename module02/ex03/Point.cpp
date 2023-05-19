/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:41:18 by franmart          #+#    #+#             */
/*   Updated: 2023/05/19 11:43:25 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point():_x(0), _y(0)
{
}

Point::Point(const float x, const float y):_x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point()
{
}

Point::Point(Point const &copy): _x(copy._x), _y(copy._y)
{
}

Fixed Point::getX(void) const
{
  return (this->_x);
}

Fixed Point::getY(void) const
{
  return (this->_y);
}

Point	&Point::operator=(const Point &copy)
{
	(void) copy;
	return (*this);
}
