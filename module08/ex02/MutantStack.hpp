/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:09:46 by franmart          #+#    #+#             */
/*   Updated: 2023/08/23 17:39:34 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &copy);
		typedef typename std::deque<T>::iterator iterator;
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
};

template <typename T>
MutantStack<T>::MutantStack() {};

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	this->c = copy.c;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
	this->c = copy.c;
	return (*this);
}

#endif
