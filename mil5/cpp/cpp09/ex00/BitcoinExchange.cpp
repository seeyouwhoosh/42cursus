/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:36 by xwu               #+#    #+#             */
/*   Updated: 2026/07/13 17:54:21 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iterator>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return *this;
}

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

int	BitcoinExchange::load_input(char *input_file)
{
	input.open(input_file);
	if (!input)
	{
		std::cout << "Error: bad input file\n";
		return 1;
	}
	if (input.peek() == std::fstream::traits_type::eof())
	{
		std::cout << "Error: empty file\n";
		return 1;
	}
	return 0;
}

int	BitcoinExchange::process_value(std::string line, float *val_ptr)
{
	float	value;
	char	*remainder;

	value = std::strtod(line.substr(line.find('|') + 1, std::string::npos).c_str(), &remainder);
	if (*remainder != '\n' && *remainder != '\0')
	{
		std::cerr << "Error: incorrect format => \"" << line << "\"\n";
		return 1;
	}
	if (value > 1000 || value < 0)
	{
		std::cerr << "Error: value must be between 0 and 1000 => " << value << "\n";
		return 1;
	}
	*val_ptr = value;
	return 0;
}

template<class InputIterator>
bool ft_all_of(InputIterator first, InputIterator last, bool (*func)(int, int), const int &param)
{
	while (first != last)
	{
		if (!func(*first, param))
			return false;
		++first;
	}
	return true;
}

template<class InputIterator>
bool ft_any_of(InputIterator first, InputIterator last, bool (*func)(int, int), const int &param)
{
	while (first != last)
	{
		if (func(*first, param))
			return true;
		++first;
	}
	return false;
}

bool	is_date(int c, int n)
{
	(void)n;
	return (std::isdigit(c) || c == '-');
}

bool	is_that_month(int c, int n)
{
	return c == n;
}

int	BitcoinExchange::process_date(std::string line, std::string *date_ptr, 
									std::map<std::string, float>::iterator *aprox_date)
{
	std::string	date;
	size_t		sep_pos;
	long		y, m, d;
	short		leap_year = 0;
	int long_months[] = {1, 3, 5, 7, 8, 10, 12};

	date = line.substr(0, line.find(" |"));
	sep_pos = date.find('-');
	if (std::count(date.begin(), date.end(), '-') != 2 ||
		!ft_all_of(date.begin(), date.end(), is_date, 0))
	{
		std::cerr << "Error: incorrect format => \"" << date << "\"\n";
		return 1;
	}

	y = std::atol(line.substr(0, sep_pos).c_str());
	if (y < 0 || y > RAND_MAX)
	{
		std::cerr << "Error: invalid year => " << date << "\n";
		return 1;
	}
	if (!(y % 4) || !(y % 4 || y % 100))
		leap_year = 1;

	m = std::atol(line.substr(sep_pos + 1, line.find('-', sep_pos + 1) - sep_pos).c_str());
	if (m < 0 || m > 12)
	{
		std::cerr << "Error: invalid month => " << date << "\n";
		return 1;
	}

	sep_pos = line.find('-', sep_pos + 1);
	d = std::atol(line.substr(sep_pos + 1, line.find('-', sep_pos + 1) - sep_pos).c_str());
	if (d < 0 || 
		(d > 31 && ft_any_of(long_months, long_months + 7, is_that_month, m)) ||
		(d > 30 && !ft_any_of(long_months, long_months + 7, is_that_month, m)) ||
		(m == 2 && ((d > 29 && leap_year) || (d > 28 && !leap_year))))
	{
		std::cerr << "Error: invalid day => " << date << "\n";
		return 1;
	}

	*date_ptr = date;
	if (exchange_rates.find(date) == exchange_rates.end())
	{
		if (exchange_rates.lower_bound(date) == exchange_rates.end())
		{
			std::cerr << "Error: too big of a date => " << date << "\n";
			return 1;
		}
		*aprox_date = exchange_rates.lower_bound(date);
	} 
	else
		*aprox_date = exchange_rates.find(date);
	return 0;
}

static void	print_header()
{
	std::cout << std::setw(10) << "Date";
	std::cout << " | ";
	std::cout << std::setw(10) << "Aprox_date";
	std::cout << " | ";
	std::cout << std::setw(7) << "Value";
	std::cout << " | ";
	std::cout << std::setw(7) << "Rate";
	std::cout << " | ";
	std::cout << std::setw(7) << "End value";
	std::cout << "\n";
	std::cout << "--------------------------------------------------------\n";
}

static void	print_row(std::string date, float value,
						std::map<std::string, float>::iterator aprox_date)
{
	std::cout.precision(4);
	std::cout << std::setw(10) << date;
	std::cout << " | ";
	std::cout << std::setw(10) << aprox_date->first;
	std::cout << " | ";
	std::cout << std::setw(7) << value;
	std::cout << " | ";
	std::cout << std::setw(7) << aprox_date->second;
	std::cout << " | ";
	std::cout << std::setw(7) << aprox_date->second * value;
	std::cout << "\n";
}

void	BitcoinExchange::exchange(char *input_file)
{
	std::string								line;
	std::string								date;
	float									value;
	std::map<std::string, float>::iterator	aprox_date;

	if (load_data())
		return;
	if (load_input(input_file))
		return;

	print_header();
	while (std::getline(input, line))
	{
		if (process_value(line, &value))
			continue;
		if (process_date(line, &date, &aprox_date))
			continue;
		print_row(date, value, aprox_date);
	}
}
