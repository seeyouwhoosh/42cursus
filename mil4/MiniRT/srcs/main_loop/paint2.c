/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:55:47 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 16:24:11 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_plane_col(t_plane *plane, double intens)
{
	int	r;
	int	g;
	int	b;

	r = (int)round((double)plane->r * intens);
	g = (int)round((double)plane->g * intens);
	b = (int)round((double)plane->b * intens);
	return ((r << 16) + (g << 8) + b);
}

int	get_sphere_col(t_sphere *sphere, double intens)
{
	int	r;
	int	g;
	int	b;

	r = (int)round((double)sphere->r * intens);
	g = (int)round((double)sphere->g * intens);
	b = (int)round((double)sphere->b * intens);
	return ((r << 16) + (g << 8) + b);
}

int	get_cyl_col(t_cylinder *cylinder, double intens)
{
	int	r;
	int	g;
	int	b;

	r = (int)round((double)cylinder->r * intens);
	g = (int)round((double)cylinder->g * intens);
	b = (int)round((double)cylinder->b * intens);
	return ((r << 16) + (g << 8) + b);
}

int	set_cyl_cap(t_pixel *px, t_cylinder *cyl, double t)
{
	px->t = t;
	px->obj = cyl;
	px->type = CYL_CAP;
	return (1);
}

int	set_cyl_body(t_pixel *px, t_cylinder *cyl, double t)
{
	px->t = t;
	px->obj = cyl;
	px->type = CYL_BODY;
	return (1);
}
