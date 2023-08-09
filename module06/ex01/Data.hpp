/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:11:14 by franmart          #+#    #+#             */
/*   Updated: 2023/08/02 13:25:39 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

# include <iostream>

class Data
{
	private:
		int	_content;

	public:
		Data();
		Data(int content);
		~Data();
		Data(Data const &copy);
		Data	&operator=(Data const &copy);
		int	getContent(void) const;
};

#endif

