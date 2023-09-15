/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:40:21 by franmart          #+#    #+#             */
/*   Updated: 2023/09/15 15:19:16 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

class BitcoinExchange::NoDbException: public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Database file 'data.csv' could not be found. Please download it "\
			"from the subject and ensure it is on the current working directory");
	}
};

BitcoinExchange::BitcoinExchange()
{
	std::ifstream db_file(DB_FILENAME);
	std::string	  line;

	if (!db_file.is_open())
		throw NoDbException();
	while (getline(db_file, line))
		insertToDb(line);
	db_file.close();
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy):_db(copy._db)
{}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		_db = copy._db;
	return *this;
}

void	BitcoinExchange::insertToDb(std::string const &line)
{
	std::time_t	date_key;		
	float		exchange_value;

	date_key = getDateFromLine(line);
	exchange_value = getExchangeFromLine(line);
	if (date_key != -1.0 && exchange_value >= 0.0)
		_db.insert(std::pair<std::time_t, float>(date_key, exchange_value));
}

float	BitcoinExchange::getDbValue(time_t key)
{
	std::map<std::time_t, float>::iterator it;
	it = _db.lower_bound(key);
	if (it != _db.end() && it->first == key)
		return (it->second);
	if (it != _db.begin())
	{
		--it;
		return (it->second);
	}
	return (-1.0);
}

/* memset here is necessary because otherwise the empty tm fields would contain garbage */
std::time_t getDateFromLine(std::string const &line, std::string delimiter) 
{
	struct tm	tm;
	std::time_t	date;
	std::string date_string;

	std::memset(&tm, 0, sizeof(struct tm));
	date_string = line.substr(0, line.find(delimiter));
	if (!strptime(date_string.c_str(), "%Y-%m-%d", &tm))
		return (-1);
	tm.tm_isdst = -1;
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	date = std::mktime(&tm);
	return date;
}

float	  getExchangeFromLine(std::string const &line, std::string delimiter)
{
	float		exchangeRate;
	std::string	numericPart;

	numericPart = line.substr(line.find(delimiter) + 1, line.length());
	try {
		exchangeRate = atof(numericPart.c_str());
		
	} catch (std::exception) {
		exchangeRate = -1.0;
	}
	return exchangeRate;
}
			
void  calculateExchange(std::string const &filename, BitcoinExchange *exchange)
{
	std::ifstream input_file(filename);
	std::string	  line;

	if (!input_file.is_open())
	{
		std::cout << "Error: couldn't open the file '" << filename << "'" << std::endl;
		return ;
	}
	while (getline(input_file, line))
	{
		if (validInput(line))
		{
			float	amount = getExchangeFromLine(line, "|");
			time_t	date_key = getDateFromLine(line, "|");
			float	exchangeRate = exchange->getDbValue(date_key);
			if (exchangeRate >= 0)
				std::cout << timeToString(&date_key) << " => " << amount << " = " << amount * exchangeRate << std::endl;
			else
				std::cout << "Error: no data available for " << timeToString(&date_key) << std::endl;
		}
	}
}

int	validInput(std::string const &line)
{
	if (line.find("|") == std::string::npos)
		std::cout << "Error: bad input => " << line << std::endl;
	else if (line.find("date") != std::string::npos)
		;
	else if (getExchangeFromLine(line, "|") < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (getExchangeFromLine(line, "|") > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else if (getDateFromLine(line) == -1)
		std::cout << "Error: date is not correct." << std::endl;
	else
		return (1);
	return (0);
}

std::string	timeToString(time_t *timestamp)
{
	char  buffer[11];

	std::strftime(buffer, 11, "%Y-%m-%d", localtime(timestamp));
	return (std::string(buffer));
}

