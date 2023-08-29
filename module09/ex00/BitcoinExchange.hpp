/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:56:14 by franmart          #+#    #+#             */
/*   Updated: 2023/08/29 17:30:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCON_EXCHANGE_HPP
#define BITCON_EXCHANGE_HPP

# define DB_FILENAME "data.csv"

# include <ctime>
# include <iostream>
# include <map>
# include <fstream>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::time_t, float> _db;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange	&operator=(BitcoinExchange const &copy);
		float	getDbValue(time_t key);
		void	insertToDb(std::string const &line);

	class NoDbException;
};

float		getExchangeFromLine(std::string const &line, std::string delimiter = ",");
std::time_t getDateFromLine(std::string const &line, std::string delimiter = ",");
int			validInput(std::string const &line);
std::string	timeToString(time_t *timestamp);
void		calculateExchange(std::string const &filename, BitcoinExchange *exchange);

#endif
