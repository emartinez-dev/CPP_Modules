/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:37:42 by franmart          #+#    #+#             */
/*   Updated: 2023/09/25 11:04:52 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <deque>
# include <string>
# include <vector>
# include <sys/time.h>
# include <algorithm>
# include <limits.h>
# include <iomanip>
# include <unistd.h>

# define ERR_INVALID_PARAMS 41
# define ERR_INPUT_DUP 42
# define ERR_INPUT_INVALID 43

/* The vector is a lot faster than the deque because it's placed continuously in the
 * memory, so when using the [] operator, it doesn't have to jump from block to block
 * of memory, the element is just: element = vector[sizeof(int) * pos] */

class PmergeMe
{
	private:
		std::deque<int>	  deq;
		std::vector<int>  vec;
		long long		  deq_time;
		long long		  vec_time;
		int				  size;

	public:
		PmergeMe();
		PmergeMe(int n);
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe	&operator=(PmergeMe const &copy);

		void  fillContainers(char **argv);
		void  mergeInsertSort(void);
		void  sortDeque(void);
		void  sortVector(void);

		void  printContainer(std::string const &context);
		void  printTimes(void) const;
		int	  getSize(void) const;
};

int			validateInput(int argc, char **argv);
std::string	printError(int error);

#endif
