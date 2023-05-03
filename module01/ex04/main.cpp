/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:08:53 by franmart          #+#    #+#             */
/*   Updated: 2023/05/03 12:49:09 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed2.hpp"

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		find;
	std::string		replace;
	std::fstream	infile;
	std::fstream	outfile;

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
	/* replace text magic goes here*/
	infile.close();
	outfile.close();
	std::cout << "Params: " << "\nfile -> " + filename << "\nfind -> " + find \
		<< "\nreplace -> " + replace << std::endl;
	return (0);
}
