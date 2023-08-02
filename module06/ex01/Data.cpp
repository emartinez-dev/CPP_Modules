/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:11:04 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 13:25:59 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data():_content(0)
{
}

Data::Data(int content):_content(content)
{

}

Data::~Data()
{
}

Data::Data(Data const &copy):_content(copy._content)
{
}

Data	&Data::operator=(const Data &copy)
{
	if (this != &copy) {
		_content = copy._content;		
	}
	return *this;
}

int	Data::getContent(void) const
{
	return _content;
}

