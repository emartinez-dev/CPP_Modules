/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:55 by franmart          #+#    #+#             */
/*   Updated: 2023/05/04 15:18:27 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed2.hpp"

bool	sed_is_for_losers(std::ifstream *infile, std::ofstream *outfile, \
							std::string *find, std::string *replace)
{
	std::ostringstream	buff;
	std::string			content;
	if (infile->good())
		buff << infile->rdbuf();
	content = buff.str();
	for (size_t i = 0; i < content.length(); i++)
	{
		i = content.find(*find, i);
		if (i > content.length()) break;
		content.erase(i, find->length());
		content.insert(i, *replace);
	}
	(*outfile) << content << std::endl;
	return (true);
}