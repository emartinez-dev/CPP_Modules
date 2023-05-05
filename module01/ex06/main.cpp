/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:39:58 by franmart          #+#    #+#             */
/*   Updated: 2023/05/05 14:53:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl 		harl;
	std::string level;

	if (argc != 2)
		return (std::cerr << ERROR_ARGS, 1);
	harl.filter = argv[1];
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	switch (harl.filter.size()) {
		case 0:
			std::cout << "[ Probably complaining about insignificant "\
				"problems ]" << std::endl;
			break;
		default:
			break;
	}
}
