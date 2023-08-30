/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:56:17 by franmart          #+#    #+#             */
/*   Updated: 2023/08/30 12:53:37 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &copy):_operands(copy._operands)
{
}

RPN	&RPN::operator=(const RPN &copy)
{
	if (this != &copy) {
		_operands = copy._operands;
	}
	return *this;
}

//std::stack<char> fillOperands(std::string const &input)
int  RPN::operate(std::string const &ops)
{
	_error = 0;
	for (int i = 0; ops[i]; i++)
	{
		if (isspace(ops[i]))
			;
		else if (isnumber(ops[i]))
		{
			_operands.push(ops[i] - '0');
		}
		else if (ops[i] == '+' || ops[i] == '-' || ops[i] == '*' || ops[i] == '/')
		{
			if (_operands.size() < 2)
			{
				_error = ERROR_NO_ELEMS;
				return (0);
			}
			int x, y;
			x = _operands.top();
			_operands.pop();
			y = _operands.top();
			_operands.pop();
			switch (ops[i]) {
				case '+':
					_operands.push(y + x);
					break;
				case '-':
					_operands.push(y - x);
					break;
				case '*':
					_operands.push(y * x);
					break;
				case '/':
					_operands.push(y / x);
					break;
			}
		}
		else
		{
			_error = ERROR_NOT_VALID_OP;
			return (0);
		}
	}
	return (1);
}

int  RPN::getResult(void)
{
	int	result = 0;
	if (!_error && _operands.size() == 1)
	{
		result = _operands.top();
		_operands.pop();
	}
	else if (!_error && _operands.size() != 1)
	{
		_error = ERROR_STACK_NOT_EMPTY;	
	}
	return (result);
}

int	  RPN::checkError(void)
{
	return (_error);
}

void  RPN::printError(void)
{
	switch (_error) {
		default:
			break;
		case ERROR_NO_ELEMS:
			std::cout << "Error: Not enough elements in stack to operate\n";	
			break;
		case ERROR_STACK_NOT_EMPTY:
			std::cout << "Error: Can't return result because stack is not empty\n";	
			break;
		case ERROR_NOT_VALID_OP:
			std::cout << "Error: Unknown symbol in input\n";	
			break;
	}
}

