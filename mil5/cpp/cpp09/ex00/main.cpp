/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:40 by xwu               #+#    #+#             */
/*   Updated: 2026/07/08 02:15:39 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

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


	std::map<std::string, float>	exchange_rates;
	std::string							line;

	std::getline(csv_db, line);
	while (std::getline(csv_db, line))
	{
		std::string		date = line.substr(0, 10);
		float	rate = std::atof(line.substr(line.find(',') + 1, std::string::npos).c_str());
		std::cout << date << " " <<std::setprecision(7) << rate << "\n";
		exchange_rates[date] = rate;
	}

	
}