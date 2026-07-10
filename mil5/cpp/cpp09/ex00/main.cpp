/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:22:40 by xwu               #+#    #+#             */
/*   Updated: 2026/07/10 12:09:03 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
	BitcoinExchange	btc;

	if (ac != 2)
	{
		std::cout << "Error: No file specified\n";
		return 1;
	}

	btc.exchange(av[1]);
}