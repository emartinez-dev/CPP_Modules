/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:33:55 by franmart          #+#    #+#             */
/*   Updated: 2023/05/05 11:29:38 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed2.hpp"

void	sed_is_for_losers(std::ifstream *infile, std::ofstream *outfile, \
							std::string *find, std::string *replace)
{
	std::ostringstream	buff;
	std::string			content;

	if (!infile->good())
		return ;
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
}
