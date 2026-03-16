/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:18:14 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/02/28 16:52:50 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	plus_fov(t_camera *cam)
{
	int	new_fov;

	new_fov = cam->fov + FOV;
	if (new_fov > 180)
		return (SUCCESS);
	cam->fov = new_fov;
	cam->f = WIDTH / (2 * tan((double)(cam->fov * PI / 180.0) / 2.0));
	return (SUCCESS);
}

int	minus_fov(t_camera *cam)
{
	int	new_fov;

	new_fov = cam->fov - FOV;
	if (new_fov <= 0)
		return (SUCCESS);
	cam->fov = new_fov;
	cam->f = WIDTH / (2 * tan(((double)cam->fov * PI / 180.0) / 2.0));
	return (SUCCESS);
}

int	add_fov(t_camera *cam)
{
	int	x;
	int	new_fov;

	ft_putendl_fd("Changing FOV, asking for change in FOV\n", 1);
	if (ask_change_fov(&x))
		return (MALLOC);
	new_fov = cam->fov + x;
	if (new_fov <= 0 || new_fov > 180)
	{
		ft_putendl_fd("Resulting FOV is out of bounds, ignoring", 1);
		return (SUCCESS);
	}
	cam->fov = new_fov;
	cam->f = WIDTH / (2 * tan((double)(cam->fov) / 2.0));
	return (SUCCESS);
}

int	resize_sphere_plus(t_sphere *sphere)
{
	double	check;

	check = sphere->r * SCALE;
	if (check != INFINITY)
		sphere->r = check;
	return (SUCCESS);
}

int	resize_sphere_minus(t_sphere *sphere)
{
	double	check;

	check = sphere->r / SCALE;
	if (check != 0.0)
		sphere->r = check;
	return (SUCCESS);
}
