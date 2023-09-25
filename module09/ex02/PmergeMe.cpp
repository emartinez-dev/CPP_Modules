/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:37:40 by franmart          #+#    #+#             */
/*   Updated: 2023/09/25 10:57:51 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe():deq_time(0), vec_time(0),size(0)
{
}

PmergeMe::PmergeMe(int n):deq_time(0), vec_time(0), size(n)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &copy):deq(copy.deq), vec(copy.vec)
{
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy) {
		deq = copy.deq;
		vec = copy.vec;
	}
	return *this;
}

static long long getTime(void);

void  PmergeMe::mergeInsertSort(void)
{
	long long	start_time, end_time;

	start_time = getTime();
	sortDeque();
	end_time = getTime();
	deq_time = end_time - start_time;

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

static void  mergeSortDeque(std::deque<int> &deque, int l, int r);
static void  mergeDeque(std::deque<int> &deque, int left, int mid, int right);
static void  insertionSortDeque(std::deque<int> &deque);

void  PmergeMe::sortDeque(void)
{
	if (deq.size() < 2)
		return;
	int mid = deq.size() / 2;
	std::deque<int> left(deq.begin(), deq.begin() + mid);
	std::deque<int> right(deq.begin() + mid, deq.end());

	mergeSortDeque(left, 0, left.size() - 1);
	insertionSortDeque(right);
	
	std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());

}

static void  mergeSortVector(std::vector<int> &vec, int l, int r);
static void  mergeVector(std::vector<int> &vec, int left, int mid, int right);
static void  insertionSortVector(std::vector<int> &vec);

void  PmergeMe::sortVector(void)
{
	if (vec.size() < 2)
		return;
	int mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	mergeSortVector(left, 0, left.size() - 1);
	insertionSortVector(right);
	
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
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
		deq.push_back(n);
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
	
	std::cout << s1 << getSize() << s2 << "std::deque  :  " 
		<< deq_time << " us" << std::endl;
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
		if (num < 0 || num > INT_MAX || !isdigit(argv[i][0]))
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

static void  mergeSortVector(std::vector<int> &vec, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSortVector(vec, l, m);
		mergeSortVector(vec, m + 1, r);
		mergeVector(vec, l, m, r);
	}
}

static void  mergeVector(std::vector<int> &vec, int left, int mid, int right)
{
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	std::vector<int> L(leftSize), R(rightSize);
	
	for (int i = 0; i < leftSize; i++)
		L[i] = vec[left + i];
	for (int i = 0; i < rightSize; i++)
		R[i] = vec[mid + 1 + i];
	
	int i = 0;
	int j = 0;
	int merge = left;

	while (i < leftSize && j < rightSize)
	{
		if (L[i] <= R[j])
			vec[merge++] = L[i++];
		else
			vec[merge++] = R[j++];
	}
	
	while (i < leftSize)
		vec[merge++] = L[i++];
	while (j < rightSize)
		vec[merge++] = R[j++];
}

static void  insertionSortVector(std::vector<int> &vec)
{
	for (size_t i = 1; i < vec.size(); i++)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

static void  mergeSortDeque(std::deque<int> &deque, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSortDeque(deque, l, m);
		mergeSortDeque(deque, m + 1, r);
		mergeDeque(deque, l, m, r);
	}
}

static void  mergeDeque(std::deque<int> &deque, int left, int mid, int right)
{
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	std::vector<int> L(leftSize), R(rightSize);
	
	for (int i = 0; i < leftSize; i++)
		L[i] = deque[left + i];
	for (int i = 0; i < rightSize; i++)
		R[i] = deque[mid + 1 + i];
	
	int i = 0;
	int j = 0;
	int merge = left;

	while (i < leftSize && j < rightSize)
	{
		if (L[i] <= R[j])
			deque[merge++] = L[i++];
		else
			deque[merge++] = R[j++];
	}
	
	while (i < leftSize)
		deque[merge++] = L[i++];
	while (j < rightSize)
		deque[merge++] = R[j++];
}

static void  insertionSortDeque(std::deque<int> &deque)
{
	for (size_t i = 1; i < deque.size(); i++)
	{
		int key = deque[i];
		int j = i - 1;
		while (j >= 0 && deque[j] > key)
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = key;
	}
}

