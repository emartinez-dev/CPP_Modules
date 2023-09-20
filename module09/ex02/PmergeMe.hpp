/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:37:42 by franmart          #+#    #+#             */
/*   Updated: 2023/09/20 16:54:46 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <list>
# include <string>
# include <vector>
# include <sys/time.h>

# define ERR_INVALID_PARAMS 41
# define ERR_INPUT_DUP 42
# define ERR_INPUT_INVALID 43

class PmergeMe
{
	private:
		std::list<int>	  lst;
		std::vector<int>  vec;
		long long		  lst_time;
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
		void  sortList(void);
		void  sortVector(void);

		void  printContainer(std::string const &context);
		void  printTimes(void) const;
		int	  getSize(void) const;
};

int			validateInput(int argc, char **argv);
std::string	printError(int error);

#endif
