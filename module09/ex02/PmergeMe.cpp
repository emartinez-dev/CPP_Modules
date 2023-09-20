/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:37:40 by franmart          #+#    #+#             */
/*   Updated: 2023/09/20 16:54:20 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <unistd.h>
#include <vector>

PmergeMe::PmergeMe():lst_time(0), vec_time(0),size(0)
{
}

PmergeMe::PmergeMe(int n):lst_time(0), vec_time(0), size(n)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &copy):lst(copy.lst), vec(copy.vec)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy) {
		lst = copy.lst;
		vec = copy.vec;
	}
	return *this;
}

static long long getTime(void);

void  PmergeMe::mergeInsertSort(void)
{
	long long	start_time, end_time;

	start_time = getTime();
	sortList();
	end_time = getTime();
	lst_time = end_time - start_time;

	start_time = getTime();
	sortVector();
	end_time = getTime();
	vec_time = end_time - start_time;
}

static long long getTime(void)
{
	timeval	  time;
	long long total;

	gettimeofday(&time, NULL);
	total = time.tv_sec * 1e6;
	total += time.tv_usec;
	return (total);
}

void  PmergeMe::sortList(void)
{
}

void  PmergeMe::sortVector(void)
{
}

int	  PmergeMe::getSize(void) const
{
	return size;
}

void  PmergeMe::fillContainers(char **argv)
{
	int	n;

	for (int i = 1; argv[i]; i++)
	{
		n = atoi(argv[i]);
		lst.push_back(n);
		vec.push_back(n);
	}
}

void  PmergeMe::printContainer(std::string const &context)
{
	std::cout << context << "\t";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void  PmergeMe::printTimes() const
{
	std::string	s1, s2;

	s1 = "Time to process a range of ";
	s2 = " elements with ";
	
	std::cout << s1 << getSize() << s2 << "std::list   :  " 
		<< lst_time << " us" << std::endl;
	std::cout << s1 << getSize() << s2 << "std::vector :  " 
		<< vec_time << " us" << std::endl;
}

static int	find(std::vector<long> vec, long n);

int	validateInput(int argc, char **argv)
{
	std::vector<long> num_set;
	long			  num;

	if (argc < 2)
		return (ERR_INVALID_PARAMS);
	for (int i = 1; argv[i]; i++)
	{
		num = atol(argv[i]);
		if (num < 0 || num > INT_MAX || !isnumber(argv[i][0]))
			return (ERR_INPUT_INVALID);
		if (find(num_set, num))
			return (ERR_INPUT_DUP);
		num_set.push_back(num);
	}
	return (0);
}

std::string	printError(int error)
{
	switch (error) {
		case ERR_INVALID_PARAMS:
			return ("Error: not enough parameters\n");
		case ERR_INPUT_DUP:
			return ("Error: numbers must be unique\n");
		case ERR_INPUT_INVALID:
			return ("Error: numbers must be positive and less than INT_MAX\n");
	}
	return ("");
}

static int	find(std::vector<long> vec, long n)
{
	if (vec.size() == 0)
		return (0);
	for (std::vector<long>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (n == *it)
			return (1);
	}
	return (0);
}
