/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:06:36 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 16:24:26 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	paint(t_screen *screen, t_pixel *point, int p)
{
	char	*dst;

	dst = screen->img_addr + (point->y * screen->img_length + point->x
			* (screen->bits_per_pixel / 8));
	*(unsigned int *)dst = p;
}

int	get_col(t_pixel *pixel, double intens)
{
	if (!pixel->type)
		return (0);
	else if (pixel->type == PLANE)
		return (get_plane_col((t_plane *)pixel->obj, intens));
	else if (pixel->type == SPHERE)
		return (get_sphere_col((t_sphere *)pixel->obj, intens));
	else if (pixel->type == CYL_BODY || pixel->type == CYL_CAP)
		return (get_cyl_col((t_cylinder *)pixel->obj, intens));
	return (0);
}

double	get_lamp2(t_miniRT *rt, t_vec point, t_pixel *px)
{
	size_t	i;
	double	len;
	t_vec	dir;

	dir = points_vec(point, rt->light->pos);
	len = norm(dir);
	normalise(&dir);
	i = -1;
	while (++i < rt->cylinders->length)
	{
		intersect_cylinder(rt->cylinders->cylinders + i, dir, px, point);
		if (px->t + TOL < len)
			return (0);
	}
	return (rt->light->bright / (C + len * (L + len * K)));
}

double	get_lamp(t_vec point, t_miniRT *rt, t_pixel *px, t_vec grad)
{
	size_t	i;
	t_vec	dir;
	double	len;

	dir = points_vec(point, rt->light->pos);
	len = norm(dir);
	normalise(&dir);
	i = -1;
	while (++i < rt->planes->length)
	{
		intersect_plane(rt->planes->planes + i, dir, px, point);
		if (px->t + TOL < len)
			return (0);
	}
	i = -1;
	while (++i < rt->spheres->length)
	{
		intersect_sphere(rt->spheres->spheres + i, dir, px, point);
		if (px->t + TOL < len)
			return (0);
	}
	return (get_lamp2(rt, point, px) * fmax(0, dot_prod(dir, grad)));
}

int	get_true_col(t_miniRT *rt, t_pixel *px, t_vec vec)
{
	double	intens;
	t_vec	point;
	t_pixel	pixel;
	t_vec	grad;
	double	lamp;

	if (px->type == NONE)
		return (0);
	pixel.t = INFINITY;
	pixel.type = NONE;
	pixel.obj = NULL;
	intens = rt->ambient_light->bright;
	point = add(rt->camera->pos, times(vec, px->t));
	grad = get_grad(px, rt->camera, point);
	lamp = get_lamp(point, rt, &pixel, grad);
	intens = fmin(1, intens + lamp);
	return (get_col(px, intens));
}
