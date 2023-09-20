/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:03:56 by franmart          #+#    #+#             */
/*   Updated: 2023/09/20 14:07:56 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	int	error;

	error = validateInput(argc, argv);
	if (error)
	{
		std::cout << printError(error);
		return (error);
	}
	PmergeMe sorter(argc - 1);

	sorter.fillContainers(argv);
	sorter.printContainer("Before:");

	sorter.mergeInsertSort();

	sorter.printContainer("After:");
	sorter.printTimes();
	return (0);
}
