/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:19:46 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 11:14:53 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();
}

template <typename T>
Array<T>::Array(const Array &copy): _array(new T[copy.size()]), _size(copy.size())
{
	for (unsigned int i = 0; i < copy.size(); i++)
		_array[i] = copy._array[i];
}


template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	if (this == &copy)
		return (*this);
	_array = new T[copy.size()];
	_size = copy.size();
	for (unsigned int i = 0; i < copy.size(); i++)
		_array[i] = copy._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	else
		return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif
