/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:05:43 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 16:24:38 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	get_grad(t_pixel *px, t_camera *cam, t_vec pos)
{
	t_vec	grad;

	if (px->type == PLANE)
		grad = ((t_plane *)px->obj)->dir;
	else if (px->type == CYL_CAP)
		grad = ((t_cylinder *)px->obj)->dir;
	else if (px->type == SPHERE)
		grad = points_vec(pos, ((t_sphere *)px->obj)->pos);
	else if (px->type == CYL_BODY)
		grad = points_vec(points_vec(((t_cylinder *)px->obj)->pos, pos),
				times(((t_cylinder *)px->obj)->dir,
					dot_prod(points_vec(((t_cylinder *)px->obj)->pos, pos),
						((t_cylinder *)px->obj)->dir)));
	if (dot_prod(grad, cam->dir) >= 0)
		grad = times(grad, -1.0);
	normalise(&grad);
	return (grad);
}

t_vec	choose_dir(t_pixel *pixel, t_camera *camera)
{
	double	a;
	double	b;
	t_vec	dir;

	a = (((double)pixel->x + 0.5 - (double)WIDTH / 2.0)) / camera->f;
	b = ((-(double)pixel->y - 0.5 + (double)HEIGHT / 2.0)) / camera->f;
	dir.x = a * camera->right.x + b * camera->up.x + camera->dir.x;
	dir.y = a * camera->right.y + b * camera->up.y + camera->dir.y;
	dir.z = a * camera->right.z + b * camera->up.z + camera->dir.z;
	normalise(&dir);
	return (dir);
}

void	choose_color(t_screen *screen, t_pixel *pixel, t_vec dir, t_miniRT *rt)
{
	size_t	i;

	i = -1;
	while (++i < rt->planes->length)
		intersect_plane(rt->planes->planes + i, dir, pixel, rt->camera->pos);
	i = -1;
	while (++i < rt->spheres->length)
		intersect_sphere(rt->spheres->spheres + i, dir, pixel, rt->camera->pos);
	i = -1;
	while (++i < rt->cylinders->length)
		intersect_cylinder
			(rt->cylinders->cylinders + i, dir, pixel, rt->camera->pos);
	paint(screen, pixel, get_true_col(rt, pixel, dir));
}

int	loop(t_miniRT *rt)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			choose_color(rt->screen, rt->screen->screen
				+ (WIDTH * j + i), choose_dir(rt->screen->screen
					+ (WIDTH * j + i), rt->camera), rt);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(rt->screen->mlx,
		rt->screen->window, rt->screen->img, 0, 0);
	return (SUCCESS);
}
