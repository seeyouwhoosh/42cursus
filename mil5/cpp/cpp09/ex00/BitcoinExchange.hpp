/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:19 by xwu               #+#    #+#             */
/*   Updated: 2026/07/24 20:24:36 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>

typedef struct date_s
{
	long	y, m, d;
}			date_t;

class BitcoinExchange
{
private:
	std::map<std::string, float>	exchange_rates;
	std::fstream					input;

	int	load_data();
	int	load_input(char *input_file);
	int	process_value(std::string line, float &val);
	int	process_date(std::string line, std::string &date, std::map<std::string, float>::iterator &aprox_date);
	int	get_aprox_date(std::string &date, std::map<std::string, float>::iterator &aprox_date);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void exchange(char *input_file);
};


