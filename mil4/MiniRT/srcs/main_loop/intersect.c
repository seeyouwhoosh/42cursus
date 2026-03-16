/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:52:12 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 11:50:50 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_plane(t_plane *plane,
		t_vec dir, t_pixel *pixel, t_vec pos)
{
	double	denom;
	double	numer;
	double	t;

	denom = dot_prod(plane->dir, dir);
	numer = -dot_prod(plane->dir, points_vec(plane->pos, pos));
	if (denom != 0.0)
		t = numer / denom;
	else
		return (0);
	if (t < pixel->t && t > TOL)
	{
		pixel->t = t;
		pixel->obj = plane;
		pixel->type = PLANE;
		return (1);
	}
	return (0);
}

int	intersect_sphere(t_sphere *sphere, t_vec dir,
		t_pixel *pixel, t_vec pos)
{
	double	m;
	double	c;
	double	dis;
	double	t;

	m = dot_prod(dir, points_vec(pos, sphere->pos));
	c = dot_prod(points_vec(pos, sphere->pos),
			points_vec(pos,
				sphere->pos)) - sphere->d * sphere->d;
	dis = m * m - c;
	if (dis < 0.0)
		return (0);
	dis = sqrt(dis);
	if (m - dis > TOL)
		t = m - dis;
	else
		t = m + dis;
	if (t < pixel->t && t > TOL)
	{
		pixel->t = t;
		pixel->obj = sphere;
		pixel->type = SPHERE;
		return (1);
	}
	return (0);
}

static int	shell(t_cylinder *cyl, t_why why, t_pixel *px)
{
	double	a;
	double	b;
	double	t;
	double	dis;

	a = dot_prod(why.vt, why.vt);
	b = 2 * dot_prod(why.vt, why.wt);
	dis = b * b - 4 * a * (dot_prod(why.wt, why.wt) - cyl->d * cyl->d);
	if (dis < 0)
		return (0);
	dis = sqrt(dis);
	t = (-b - dis) / (2 * a);
	if (t > TOL && t < px->t && cyl->h / 2
		>= fabs(dot_prod(cyl->dir, add(why.w, times(why.dir, t)))))
		return (set_cyl_body(px, cyl, t));
	t = (-b + dis) / (2 * a);
	if (t > TOL && t < px->t && cyl->h / 2
		>= fabs(dot_prod(cyl->dir, add(why.w, times(why.dir, t)))))
		return (set_cyl_body(px, cyl, t));
	return (0);
}

static int	caps(t_cylinder *cyl, t_why why, t_pixel *px)
{
	double	t;
	t_vec	p;
	double	denom;
	int		check;

	denom = dot_prod(why.dir, cyl->dir);
	check = 0;
	if (denom == 0.0)
		return (0);
	p = add(cyl->pos, times(cyl->dir, cyl->h / 2));
	t = dot_prod(points_vec(why.q, p), cyl->dir) / denom;
	if (t > TOL && t < px->t && cyl->d
		>= norm(points_vec(p, add(why.q, times(why.dir, t)))))
		check = set_cyl_cap(px, cyl, t);
	p = points_vec(times(cyl->dir, cyl->h / 2), cyl->pos);
	t = dot_prod(points_vec(why.q, p), cyl->dir) / denom;
	if (t > TOL && t < px->t && cyl->d
		>= norm(points_vec(p, add(why.q, times(why.dir, t)))))
		check = set_cyl_cap(px, cyl, t);
	return (check);
}

int	intersect_cylinder(t_cylinder *cylinder, t_vec dir,
		t_pixel *pixel, t_vec pos)
{
	t_why	why;
	int		check;

	check = 0;
	why.w = points_vec(cylinder->pos, pos);
	why.vt = times(cylinder->dir, dot_prod(dir, cylinder->dir));
	why.wt = times(cylinder->dir, dot_prod(why.w, cylinder->dir));
	why.vt = points_vec(why.vt, dir);
	why.wt = points_vec(why.wt, why.w);
	why.dir = dir;
	why.q = pos;
	if (shell(cylinder, why, pixel))
		check = 1;
	if (caps(cylinder, why, pixel))
		check = 1;
	return (check);
}
