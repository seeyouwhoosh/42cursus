/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:58:55 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 18:56:19 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	move_cam(t_camera *camera, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	x = 0;
	y = 0;
	z = 0;
	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	camera->pos.x += x;
	camera->pos.y += y;
	camera->pos.z += z;
	return (SUCCESS);
}

int	place_cam(t_camera *camera, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	x = 0;
	y = 0;
	z = 0;
	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	camera->pos.x = x;
	camera->pos.y = y;
	camera->pos.z = z;
	return (SUCCESS);
}

int	move_cam_from(t_camera *camera, t_miniRT *rt)
{
	t_vec	coefs;

	coefs.x = 0;
	coefs.y = 0;
	coefs.z = 0;
	(void)rt;
	if (ask_coords(&(coefs.x), &(coefs.y), &(coefs.z)))
		return (MALLOC);
	translate_base(&(camera->pos), camera, coefs);
	return (SUCCESS);
}

int	move_plane(t_plane *plane, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	x = 0;
	y = 0;
	z = 0;
	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	plane->pos.x += x;
	plane->pos.y += y;
	plane->pos.z += z;
	return (SUCCESS);
}

int	place_plane(t_plane *plane, t_miniRT *rt)
{
	double	x;
	double	y;
	double	z;

	x = 0;
	y = 0;
	z = 0;
	(void)rt;
	if (ask_coords(&x, &y, &z))
		return (MALLOC);
	plane->pos.x = x;
	plane->pos.y = y;
	plane->pos.z = z;
	return (SUCCESS);
}
