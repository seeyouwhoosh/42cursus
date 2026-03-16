/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:16:42 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 16:33:11 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	resize_sphere(t_sphere *sphere)
{
	double	x;

	ft_putendl_fd("Resizing sphere's diameter, asking for scaling factor\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	sphere->d *= x;
	return (SUCCESS);
}

int	resize_cylinder(t_cylinder *cylinder)
{
	double	x;

	ft_putendl_fd("Resizing cylinder's diameter, \
asking for scaling factor\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	cylinder->d *= x;
	ft_putendl_fd("Resizing cylinder's height, asking for scaling factor\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	cylinder->h *= x;
	return (SUCCESS);
}

int	resize_cylinder_plus(t_cylinder *cylinder, int mode)
{
	double	check;

	if (!mode || mode == 1)
	{
		check = cylinder->d * SCALE;
		if (check != INFINITY)
			cylinder->d = check;
	}
	if (!mode || mode == 2)
	{
		check = cylinder->h * SCALE;
		if (check != INFINITY)
			cylinder->h = check;
	}
	return (SUCCESS);
}

int	resize_cylinder_minus(t_cylinder *cylinder, int mode)
{
	double	check;

	if (!mode || mode == 1)
	{
		check = cylinder->d / SCALE;
		if (check != 0.0)
			cylinder->d = check;
	}
	if (!mode || mode == 2)
	{
		check = cylinder->h / SCALE;
		if (check != 0.0)
			cylinder->h = check;
	}
	return (SUCCESS);
}

int	replace_fov(t_camera *cam)
{
	int	x;

	ft_putendl_fd("Changing FOV, asking for new FOV\n", 1);
	if (ask_fov(&x))
		return (MALLOC);
	cam->fov = x;
	cam->f = WIDTH / (2 * tan((double)(cam->fov * PI / 180.0) / 2.0));
	return (SUCCESS);
}
