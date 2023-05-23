/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:40:56 by franmart          #+#    #+#             */
/*   Updated: 2023/05/18 18:51:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
  private:
    const Fixed _x;
    const Fixed _y;

  public:
    Point();
    ~Point();
    Point(const float x, const float y);
    Point(Point const &copy);
    Point	&operator=(Point const &copy);
    Fixed getX( void ) const;
    Fixed getY( void ) const;
};

#endif