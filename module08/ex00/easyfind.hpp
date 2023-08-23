/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:32:33 by franmart          #+#    #+#             */
/*   Updated: 2023/08/21 16:13:23 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>
# include <iostream>

class EasyFindException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Value not found");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator pos = find(container.begin(), container.end(), value);
	if (pos != container.end())
		return (pos);
	else
		throw EasyFindException();
}

#endif
