/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:59:11 by franmart          #+#    #+#             */
/*   Updated: 2023/08/09 17:35:26 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base  *generate(void)
{
	int result = std::rand() % 3;
	switch (result) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return new Base;
}

void  identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The object ptr is actually A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "The object ptr is actually B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "The object ptr is actually C" << std::endl;
	else	
		std::cout << "The object ptr is actually Base" << std::endl;
}

void  identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "The object ref is actually A" << std::endl;
		(void) a;
		return ;
	}
	catch (std::exception) {}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "The object ref is actually B" << std::endl;
		(void) b;
		return ;
	}
	catch (std::exception) {}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "The object ref is actually C" << std::endl;
		(void) c;
		return ;
	}
	catch (std::exception) {}
	std::cout << "The object ref is actually Base" << std::endl;
}

