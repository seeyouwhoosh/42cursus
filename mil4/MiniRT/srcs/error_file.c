/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:43:26 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 16:27:25 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	errormsg(int flag)
{
	if (flag == IN_AM)
		ft_putendl_fd("Error: can only input the name of a single\
 .rt file", 2);
	else if (flag == FILE_NAME)
		ft_putendl_fd("Error: Input file must have .rt format", 2);
	else if (flag == FILE_NOT_FOUND)
		ft_putendl_fd("Error: Given file doesn't exist or could\
 not be opened", 2);
	else if (flag == MALLOC)
		ft_putendl_fd("Error: A memory allocation failed\
or ctrl d was pressed", 2);
	else if (flag == UNKNOWN_SPECIFIER)
		ft_putendl_fd("Error: unknown character given in file", 2);
	else if (flag == WRONG_SPECIFIER)
		ft_putendl_fd("Error: Some number does not fit in its range", 2);
	else if (flag == MULTIPLE_MANDATORY)
		ft_putendl_fd("Error: Camera, light or ambient light was defined\
 more than once", 2);
	else if (flag == NO_MANDATORY)
		ft_putendl_fd("Error: Camera, light or ambient\
 light was not defined", 2);
	else if (flag == NO_MANDATORY)
		ft_putendl_fd("Error: Missing mandatory elements or empty file", 2);
	else if (flag == NO_DIR)
		ft_putendl_fd("Error: Direction 0,0,0 given", 2);
}
