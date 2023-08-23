/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:43:48 by franmart          #+#    #+#             */
/*   Updated: 2023/08/23 17:39:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "MutantStack part _______________________________" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "Content:\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\nList part _____________________________________" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);

	lst.push_back(0);
	std::list<int>::iterator it_lst = lst.begin();
	std::list<int>::iterator ite_lst = lst.end();
	++it_lst;
	--it_lst;
	std::cout << "Content:\n";
	while (it_lst != ite_lst)
	{
		std::cout << *it_lst << std::endl;
		++it_lst;
	}

	std::cout << "\nVector part __________________________________" << std::endl;
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << vec.back() << std::endl;
	vec.pop_back();
	std::cout << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);

	vec.push_back(0);
	std::vector<int>::iterator itv = vec.begin();
	std::vector<int>::iterator itev = vec.end();
	++itv;
	--itv;
	std::cout << "Content:\n";
	while (itv != itev)
	{
		std::cout << *itv << std::endl;
		++itv;
	}
	{
		std::cout << "\nCopy operator test _______________________" << std::endl;
		MutantStack<int> mstack2(mstack);
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		std::cout << "Content:\n";
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
	{
		std::cout << "\nAssignment copy operator test _____________" << std::endl;
		MutantStack<int> mstack2 = mstack;
		MutantStack<int>::iterator it2 = mstack2.begin();
		MutantStack<int>::iterator ite2 = mstack2.end();
		std::cout << "Content:\n";
		while (it2 != ite2)
		{
			std::cout << *it2 << std::endl;
			++it2;
		}
	}
	return (0);

}
