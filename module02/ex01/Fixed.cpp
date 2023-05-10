/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:17:13 by franmart          #+#    #+#             */
/*   Updated: 2023/05/10 13:03:55 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* How fixed point works: it reserves the last 8 bits of the number to store the
decimal part. To convert from int to fixed point, we must shift the number 8
times to the left.

Ex: integer 231 to fixed point
						231 -> 00000000 00000000 00000000 11100111
We want to convert it into 	-> 00000000 00000000 11100111 00000000
						(we just have to shift it to the left)

But for float numbers, the shifting can't be done because as its name implies,
"floating point" means that the dot is floating on the binary number. I found
a formula to convert from floating to fixed:

	fixed = roundf(floating * 2 ^ fractional_bits) */

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed():_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (value << Fixed::_fractional_bits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fractional_bits));
}

/* A copy constructor creates a new object as a copy of an existing object */
Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/* The copy assignment operator assigns one object to another object. It's
a good practice to check for self assignment, because it can lead to memory
leaks, corruption of data or undefined behavior. */
Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_value / (float)(1 << Fixed::_fractional_bits));
}


int	Fixed::toInt( void ) const
{
	return (this->_value / (1 << Fixed::_fractional_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& number)
{
	os << number.toFloat();
	return os;
}
