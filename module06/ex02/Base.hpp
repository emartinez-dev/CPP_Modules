/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:55:19 by franmart          #+#    #+#             */
/*   Updated: 2023/09/01 11:32:10 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

# include <iostream>
# include <stdlib.h>
# include <unistd.h>
# include <exception>

class Base
{
	private:

	public:
		virtual ~Base();
};

Base  *generate(void);
void  identify(Base *p);
void  identify(Base &p);

#endif
