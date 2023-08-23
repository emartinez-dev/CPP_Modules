/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:34:52 by franmart          #+#    #+#             */
/*   Updated: 2023/08/23 14:59:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

class Span::NotEnoughNumbersException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Span must have 2 or more elements in order to be calculated");
	}
};

class Span::NotEnoughSpaceException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Span reached its max size, can't add more elements");
	}
};

Span::Span():_n(0),_max(0)
{
}

Span::Span(unsigned int N):_n(0),_max(N)
{
}

Span::~Span()
{
}

Span::Span(Span const &copy):_n(copy._n),_max(copy._max),_vec(copy._vec)
{
}

Span	&Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_n = copy._n;
		_max = copy._max;
		_vec = copy._vec;
	}
	return *this;
}

void	Span::addNumber(int number)
{
	if (_n >= _max)
		throw NotEnoughSpaceException();
	_vec.push_back(number);
	_n++;
}

int		Span::shortestSpan()
{
	if (_n <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> vec_copy = _vec;
	std::sort(vec_copy.begin(), vec_copy.end());
	int distance = vec_copy[1] - vec_copy[0];
	int	size = vec_copy.size();

	for (int i = 1; i < size - 1; i++)
	{
		if (vec_copy[i + 1] - vec_copy[i] < distance)
			distance = vec_copy[i + 1] - vec_copy[i];
		if (distance == 0)
			break;
	}
	return (distance);
	
}

int		Span::longestSpan()
{
	if (_n <= 1)
		throw NotEnoughNumbersException();
	std::vector<int>::iterator min, max;
	min = std::min_element(_vec.begin(), _vec.end());
	max = std::max_element(_vec.begin(), _vec.end());
	return (*max - *min);
}

void	Span::fillRandom()
{
	_vec = std::vector<int>(_max, 0);
	std::generate(_vec.begin(), _vec.end(), rand);
	_n = _max;
}

int Span::operator[](unsigned int index)
{
	if (index >= _max)
		throw std::exception();
	else
		return _vec[index];
}

