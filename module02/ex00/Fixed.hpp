/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:39 by franmart          #+#    #+#             */
/*   Updated: 2023/05/08 12:04:37 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractional_bits;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
