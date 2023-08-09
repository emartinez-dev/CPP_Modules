/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:55:19 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 17:35:25 by franmart         ###   ########.fr       */
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
		Base();
		virtual ~Base();
};

Base  *generate(void);
void  identify(Base *p);
void  identify(Base &p);

#endif
