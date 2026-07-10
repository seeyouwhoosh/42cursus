/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:19 by xwu               #+#    #+#             */
/*   Updated: 2026/07/10 01:44:07 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, float>	exchange_rates;
	std::fstream					input;

	int				load_data();
	std::fstream	&load_input(char *input_file);
	int				process_value(std::string line, float *val_ptr);
	int				BitcoinExchange::process_date(std::string line, std::string *date_ptr, std::map<std::string, float>::iterator *aprox_date);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	void exchange(char *input_file);
};


