/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:15:39 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 19:46:48 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	ask_coords3(double *z, char *str)
{
	write_ask("Write the z coordinate", z);
	while (1)
	{
		*z = 0;
		str = get_next_line(0);
		remove_nl(str);
		if (ft_atod(str, z))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
		{
			free(str);
			str = NULL;
			break ;
		}
	}
	return (SUCCESS);
}

static int	ask_coords2(double *y, double *z, char *str)
{
	write_ask("Write the y coordinate", y);
	while (1)
	{
		*y = 0;
		str = get_next_line(0);
		remove_nl(str);
		if (ft_atod(str, y))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
		{
			free(str);
			str = NULL;
			break ;
		}
	}
	return (ask_coords3(z, str));
}

int	ask_coords(double *x, double *y, double *z)
{
	char	*str;

	write_ask("Write the x coordinate", x);
	while (1)
	{
		*x = 0;
		str = get_next_line(0);
		remove_nl(str);
		if (ft_atod(str, x))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again:", 1);
		}
		else
		{
			free(str);
			str = NULL;
			break ;
		}
	}
	return (ask_coords2(y, z, str));
}

int	ask_factor(double *x)
{
	char	*str;

	write_ask("Write the factor", x);
	while (1)
	{
		*x = 0;
		str = get_next_line(0);
		remove_nl(str);
		if (ft_atod(str, x))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect decimal number, try again: ", 1);
		}
		else
		{
			free(str);
			break ;
		}
	}
	return (SUCCESS);
}

int	ask_fov(int *x)
{
	char	*str;

	write_ask("Write the FOV", (double *)x);
	while (1)
	{
		*x = 0;
		str = get_next_line(0);
		remove_nl(str);
		if (ft_ft_atoi(str, x))
		{
			if (!str)
				return (MALLOC);
			free(str);
			ft_putendl_fd("Incorrect integer, try again: ", 1);
		}
		else
		{
			free(str);
			if (*x > 0 && *x <= 180)
				break ;
			else
				ft_putendl_fd("FOV is in range [1, 180], try again: ", 1);
		}
	}
	return (SUCCESS);
}
