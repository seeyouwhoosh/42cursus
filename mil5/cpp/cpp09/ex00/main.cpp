/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:40 by xwu               #+#    #+#             */
/*   Updated: 2026/07/08 14:07:13 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>

/*
So, coger un input file,
para cada línea, mirar que tiene el formato adecuado
	date | value
	Year-Month-Day
	value tiene que ser float o integer (0-1000)
y multiplicar la segunda columna con el multiplicador correspondiente del spreadsheet.

container map: db
*/

int	main(int ac, char **av)
{
	/* **************************************** */

	std::fstream	csv_db("data.csv");
	std::fstream	input(av[1]);
	if (ac != 2)
	{
		std::cout << "Error: No file specified\n";
		return 1;
	}
	if (!csv_db)
	{
		std::cout << "Error: Bad data file\n";
		return 1;
	}
	if (!input)
	{
		std::cout << "Error: Bad input file\n";
		return 1;
	}

	/* **************************************** */

	std::map<std::string, float>	exchange_rates;
	std::string						line;
	std::string						date;

	std::getline(csv_db, line);
	while (std::getline(csv_db, line))
	{
		float	rate = std::atof(line.substr(line.find(',') + 1, std::string::npos).c_str());
		date = line.substr(0, 10);
		exchange_rates[date] = rate;
	}
	
	while (std::getline(input, line))
	{
		float	value = std::atof(line.substr(line.find('|') + 1, std::string::npos).c_str());
		date = line.substr(0, line.find(" |"));

		if (value > 1000 || value < 0)
		{
			std::cerr << "Error: value must be between 0 and 1000\n";
			continue;
		}

		/* **************************************** */

		if (std::count(line.begin(), line.end(), '-') > 2)
		{
			std::cerr << "Error: incorrect format\n";
			continue;
		}

		size_t	sep_pos = line.find('-');
		long	n;
		long	m;
		short	leap_year = 0;

		n = std::atol(line.substr(0, sep_pos).c_str());
		if (n < 0 || n > INT32_MAX)
		{
			std::cerr << "Error: invalid year\n";
			continue;
		}
		if (!(n % 4) || !(n % 4 || n % 100))
			leap_year = 1;
		
		sep_pos = line.find('-', sep_pos + 1);
		m = std::atol(line.substr(sep_pos, line.find('-', sep_pos + 1) - sep_pos).c_str());
		if (m < 0 || m > 12)
		{
			std::cerr << "Error: invalid month\n";
			continue;
		}
		
		sep_pos = line.find('-', sep_pos + 1);
		n = std::atol(line.substr(sep_pos, line.find('-', sep_pos + 1) - sep_pos).c_str());
		if (0 < n || (n > 31 && ((m % 2 && m < 6) || (!(m % 2) && m > 5))) || (n > 30 && (!(m % 2 && m < 6) || ((m % 2) && m > 5))) || (m == 2 && (n > 29 && leap_year || n > 28 && !leap_year)))
		{
			std::cerr << "Error: invalid day\n";
			continue;
		}

		*exchange_rates.upper_bound(date) * value;


	}
}