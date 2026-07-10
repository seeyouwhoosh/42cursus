/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:36 by xwu               #+#    #+#             */
/*   Updated: 2026/07/10 01:43:42 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange &other) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other){}

int	BitcoinExchange::load_data()
{
	std::fstream	csv_db("data.csv");
	if (!csv_db)
	{
		std::cout << "Error: bad data file\n";
		return 1;
	}

	std::string	date;
	std::string	line;
	float		rate;

	std::getline(csv_db, line);
	while (std::getline(csv_db, line))
	{
		date = line.substr(0, 10);
		rate = std::atof(line.substr(line.find(',') + 1, std::string::npos).c_str());
		exchange_rates[date] = rate;
	}

	return 0;
}

std::fstream	&BitcoinExchange::load_input(char *input_file)
{
	input.open(input_file);
	if (!input)
	{
		std::cout << "Error: bad input file\n";
		return ;
	}
}

int	BitcoinExchange::process_value(std::string line, float *val_ptr)
{
	float	value;
	char	**remainder;

	value = std::strtod(line.substr(line.find('|') + 1, std::string::npos).c_str(), remainder);
	if (**remainder != '\n' || **remainder != '\0')
	{
		std::cerr << "Error: incorrect format\n";
		return 1;
	}
	if (value > 1000 || value < 0)
	{
		std::cerr << "Error: value must be between 0 and 1000\n";
		return 1;
	}
	*val_ptr = value;
	return 0;
}

int	BitcoinExchange::process_date(std::string line, std::string *date_ptr, std::map<std::string, float>::iterator *aprox_date)
{
	std::string	date;
	size_t	sep_pos;

	date = line.substr(0, line.find(" |"));
	if (std::count(line.begin(), line.end(), '-') > 2)
	{
		std::cerr << "Error: incorrect format:" << date << "\n";
		return 1;
	}

	sep_pos = line.find('-');
	long	n;
	long	m;
	short	leap_year = 0;

	n = std::atol(line.substr(0, sep_pos).c_str());
	if (n < 0 || n > RAND_MAX)
	{
		std::cerr << "Error: invalid year\n";
		return 1;
	}
	if (!(n % 4) || !(n % 4 || n % 100))
		leap_year = 1;
	
	
	m = std::atol(line.substr(sep_pos + 1, line.find('-', sep_pos + 1) - sep_pos).c_str());
	if (m < 0 || m > 12)
	{
		std::cerr << "Error: invalid month\n";
		continue;
	}
	
	sep_pos = line.find('-', sep_pos + 1);
	n = std::atol(line.substr(sep_pos, line.find('-', sep_pos + 1) - sep_pos).c_str());
	
	if (0 < n || 
		(n > 31 && ((m % 2 && m < 6) || (!(m % 2) && m > 5))) ||
		(n > 30 && (!(m % 2 && m < 6) || ((m % 2) && m > 5))) ||
		(m == 2 && ((n > 29 && leap_year) || (n > 28 && !leap_year))))
	{
		std::cerr << "Error: invalid day\n";
		continue;
	}
}

void	BitcoinExchange::exchange(char *input_file)
{
	std::string	line;
	std::string	date;
	float		value;
	
	if (load_data())
		return;
	if (load_input(input_file))
		return;

	print_header();
	while (std::getline(input, line))
	{
		if (process_value(line, &value))
			continue;
		if (process_date(line, &date))
			continue;

			
		
		// NOTA: falta por poner el igual, es decir, cuando la fecha es igual, se debería coger la exacta. Also, no está funcionando el checking del mes
		std::map<std::string, float>::iterator	expected_date = exchange_rates.lower_bound(date);

		std::cout << date << "	";
		std::cout << " | ";
		if (date != expected_date->first)
			std::cout << expected_date->first << "	";
		else
			std::cout << " No			";
		std::cout << " | ";
		std::cout << expected_date->second << "		";
		std::cout << " | ";
		std::cout << value << "		";
		std::cout << " | ";
		std::cout << expected_date->second * value << "\n";

	}
}