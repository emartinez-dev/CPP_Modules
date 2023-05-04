/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed2.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:33:19 by franmart          #+#    #+#             */
/*   Updated: 2023/05/04 15:18:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED2_HPP
#define SED2_HPP


# include <iostream>
# include <fstream>
# include <sstream>

# define ERROR_ARGS "Invalid number of arguments. Usage: ./sed_is_for_losers "\
					"[filename] [string_to_find] [string_to_replace]\n"
# define ERROR_INFILE "The given filename could not be opened. Check that the "\
					"file exists and it has read permissions.\n"
# define ERROR_OUTFILE "The outfile could not be created and its not my fault.\n"

# define READ_MODE 1
# define WRITE_MODE 2

bool	sed_is_for_losers(std::ifstream *infile, std::ofstream *outfile, \
							std::string *find, std::string *replace);

#endif