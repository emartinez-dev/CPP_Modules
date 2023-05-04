/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:53 by franmart          #+#    #+#             */
/*   Updated: 2023/05/04 15:17:23 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed2.hpp"

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		find;
	std::string		replace;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
		return (std::cout << ERROR_ARGS, 1);
	filename = argv[1];
	find = argv[2];
	replace = argv[3];
	infile.open(filename, std::ios::in);
	if (!infile)
		return (std::cout << ERROR_INFILE, 1);
	outfile.open(filename + ".replace", std::ios::out);
	if (!outfile)
		return (std::cout << ERROR_OUTFILE, 1);
	sed_is_for_losers(&infile, &outfile, &find, &replace);
	infile.close();
	outfile.close();
	return (0);
}
