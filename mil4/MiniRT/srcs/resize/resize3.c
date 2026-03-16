/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:18:28 by xwu               #+#    #+#             */
/*   Updated: 2026/03/11 22:18:28 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	resize_light(void *light, int ambience)
{
	double	x;

	ft_putendl_fd("Adjusting light brightness, asking for scaling factor\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	if (ambience)
		((t_AmbientLight *)light)->bright *= x;
	else
		((t_light *)light)->bright *= x;
	return (SUCCESS);
}

int	resize_light_plus(void *light, int ambience)
{
	double	check;

	if (ambience)
	{
		check = ((t_AmbientLight *)light)->bright * SCALE;
		if (check != INFINITY)
			((t_AmbientLight *)light)->bright = check;
	}
	else
	{
		check = ((t_light *)light)->bright * SCALE;
		if (check != INFINITY)
			((t_light *)light)->bright = check;
	}
	return (SUCCESS);
}

int	resize_light_minus(void *light, int ambience)
{
	double	check;

	if (ambience)
	{
		check = ((t_AmbientLight *)light)->bright / SCALE;
		if (check != INFINITY)
			((t_AmbientLight *)light)->bright = check;
	}
	else
	{
		check = ((t_light *)light)->bright / SCALE;
		if (check != INFINITY)
			((t_light *)light)->bright = check;
	}
	return (SUCCESS);
}
