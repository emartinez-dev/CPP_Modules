/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:17:13 by franmart          #+#    #+#             */
/*   Updated: 2023/05/18 18:48:36 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed():_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = (value << Fixed::_fractional_bits);
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fractional_bits));
}

Fixed::Fixed(Fixed const &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &number)
{
	return (this->getRawBits() > number.getRawBits());
}

bool	Fixed::operator<(Fixed const &number)
{
	return (this->getRawBits() < number.getRawBits());
}

bool	Fixed::operator>=(Fixed const &number)
{
	return (this->getRawBits() >= number.getRawBits());
}

bool	Fixed::operator<=(Fixed const &number)
{
	return (this->getRawBits() <= number.getRawBits());
}

bool	Fixed::operator==(Fixed const &number)
{
	return (this->getRawBits() == number.getRawBits());
}

bool	Fixed::operator!=(Fixed const &number)
{
	return (this->getRawBits() != number.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &number)
{
	Fixed	tmp(*this);

	tmp.setRawBits(this->getRawBits() + number.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const &number)
{
	Fixed	tmp(*this);

	tmp.setRawBits(this->getRawBits() - number.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const &number)
{
	Fixed	tmp(*this);

	tmp.setRawBits(this->getRawBits() * number.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &number)
{
	Fixed	tmp(*this);

	if (number.getRawBits() == 0)
	{
		std::cerr << "Oh no, what are you doing! You are dividing by 0!!" \
			<< std::endl;
		return (0);
	}
	tmp.setRawBits(this->getRawBits() / number.toFloat());
	return (tmp);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed	Fixed::operator++( void )
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp = *this;
	this->_value--;
	return (tmp);
}
Fixed	Fixed::operator--( void )
{
	this->_value--;
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

Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed const &min(Fixed const &f1, Fixed const &f2)
{
	return (Fixed::min(f1, f2));
}

Fixed &min(Fixed &f1, Fixed &f2)
{
	return (Fixed::min(f1, f2));
}

Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed const &max(Fixed const &f1, Fixed const &f2)
{
	return (Fixed::max(f1, f2));
}

Fixed &max(Fixed &f1, Fixed &f2)
{
	return (Fixed::max(f1, f2));
}
