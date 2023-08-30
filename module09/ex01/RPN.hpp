/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:20:49 by franmart          #+#    #+#             */
/*   Updated: 2023/08/30 12:39:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>

# define ERROR_NO_ELEMS 1
# define ERROR_NOT_VALID_OP 2
# define ERROR_STACK_NOT_EMPTY 3

class RPN
{
	private:
		std::stack<int> _operands;
		int				_error;

	public:
		RPN();
		RPN(std::string const &input);
		~RPN();
		RPN(RPN const &copy);
		RPN	&operator=(RPN const &copy);
		int	  operate(std::string const &input);
		int	  getResult(void);
		int	  checkError(void);
		void  printError(void);
};

#endif
