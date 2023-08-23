/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:01:43 by franmart          #+#    #+#             */
/*   Updated: 2023/08/23 12:49:01 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int	  _n;
		unsigned int	  _max;
		std::vector<int>  _vec;

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(Span const &copy);
		Span	&operator=(Span const &copy);
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		void	fillRandom();
		int		randInt();
		int		operator[](unsigned int index);

		class	NotEnoughNumbersException;
		class	NotEnoughSpaceException;
};


#endif
