/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:39 by franmart          #+#    #+#             */
/*   Updated: 2023/05/10 13:24:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>
# include <ostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractional_bits;
	public:
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
		bool	operator>(Fixed const &number);
		bool	operator<(Fixed const &number);
		bool	operator>=(Fixed const &number);
		bool	operator<=(Fixed const &number);
		bool	operator==(Fixed const &number);
		bool	operator!=(Fixed const &number);
		Fixed	operator+(Fixed const &number);
		Fixed	operator-(Fixed const &number);
		Fixed	operator*(Fixed const &number);
		Fixed	operator/(Fixed const &number);
		Fixed	operator++( int );
		Fixed	operator++( void );
		Fixed	operator--( int );
		Fixed	operator--( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		static Fixed& min(Fixed &f1, Fixed &f2);
		const static Fixed& min(Fixed const &f1, Fixed const &f2);
		static Fixed& max(Fixed &f1, Fixed &f2);
		const static Fixed& max(Fixed const &f1, Fixed const &f2);
 };

std::ostream& operator<<(std::ostream& os, const Fixed& number);

#endif
