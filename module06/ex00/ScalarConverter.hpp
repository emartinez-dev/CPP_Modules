/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:05:43 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 13:17:12 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

/* Why you can't convert from float to int as easily: 
 * https://stackoverflow.com/questions/11158476/why-do-float-and-int-have-such-different-maximum-values-even-though-theyre-the
 * */

# include <iostream>
# include <string>
# include <exception>
# include <errno.h>
# include <limits>
# include <limits.h>
# include <float.h>
# include <math.h>

class ScalarConverter
{
	private:
		static char		c;
		static int		i;
		static float	f;
		static double	d;
		static char		type;

		static int		c_err;
		static int		i_err;
		static int		f_err;
		static int		d_err;

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter	&operator=(ScalarConverter const &copy);

		static void	  convert(std::string const &literal);
		static char	  getType(std::string const &literal);
		static void	  printResults(void);
		static void	  checkErrors(void);
};

bool is_number(std::string const &str);

#endif
