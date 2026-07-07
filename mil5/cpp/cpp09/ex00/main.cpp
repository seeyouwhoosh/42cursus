/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:40 by xwu               #+#    #+#             */
/*   Updated: 2026/07/07 10:57:04 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

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
	if (!csv_db.good())
	{
		std::cout << "Error: Bad data file\n";
		return 1;
	}
	if (ac != 2)
	{
		std::cout << "Error: No file specified\n";
		return 1;
	}
	std::fstream	input(av[1]);
	if (!input.good())
	{
		std::cout << "Error: Bad input file\n";
		return 1;
	}
}