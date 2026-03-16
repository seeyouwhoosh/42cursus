/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 22:21:01 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 13:51:24 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	free_all(t_miniRT *rt)
{
	if (!rt)
		return (0);
	free_cylinders(rt->cylinders);
	free_planes(rt->planes);
	free_spheres(rt->spheres);
	free_screen(rt->screen);
	if (rt->camera)
		free(rt->camera);
	if (rt->ambient_light)
		free(rt->ambient_light);
	if (rt->light)
		free(rt->light);
	free(rt);
	exit(0);
}

void	free_cylinders(t_cylinders *cylinders)
{
	if (!cylinders)
		return ;
	if (cylinders->cylinders)
		free(cylinders->cylinders);
	free(cylinders);
}

void	free_spheres(t_spheres *spheres)
{
	if (!spheres)
		return ;
	if (spheres->spheres)
		free(spheres->spheres);
	free(spheres);
}

void	free_planes(t_planes *planes)
{
	if (!planes)
		return ;
	if (planes->planes)
		free(planes->planes);
	free(planes);
}

void	free_screen(t_screen *screen)
{
	if (!screen)
		return ;
	if (screen->screen)
		free(screen->screen);
	if (!screen->mlx)
		return ;
	if (screen->img)
		mlx_destroy_image(screen->mlx, screen->img);
	if (screen->window)
		mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	free(screen);
}
