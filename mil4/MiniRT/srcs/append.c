/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:25:19 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/08 18:36:00 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_plane(t_planes *planes, t_plane plane)
{
	t_plane	*new;
	size_t	i;

	if (planes->length == planes->capacity)
	{
		planes->capacity = planes->capacity * 2;
		new = ft_calloc(sizeof(t_plane), planes->capacity);
		if (!new)
			return (MALLOC);
		i = -1;
		while (++i < planes->length)
			new[i] = planes->planes[i];
		free(planes->planes);
		planes->planes = new;
	}
	planes->planes[planes->length] = plane;
	++planes->length;
	return (SUCCESS);
}

int	add_sphere(t_spheres *spheres, t_sphere sphere)
{
	t_sphere	*new;
	size_t		i;

	if (spheres->length == spheres->capacity)
	{
		spheres->capacity = spheres->capacity * 2;
		new = ft_calloc(sizeof(t_sphere), spheres->capacity);
		if (!new)
			return (MALLOC);
		i = -1;
		while (++i < spheres->length)
			new[i] = spheres->spheres[i];
		free(spheres->spheres);
		spheres->spheres = new;
	}
	spheres->spheres[spheres->length] = sphere;
	++spheres->length;
	return (SUCCESS);
}

int	add_cylinder(t_cylinders *cylinders, t_cylinder cylinder)
{
	t_cylinder	*new;
	size_t		i;

	if (cylinders->length == cylinders->capacity)
	{
		cylinders->capacity = cylinders->capacity * 2;
		new = ft_calloc(sizeof(t_cylinder), cylinders->capacity);
		if (!new)
			return (MALLOC);
		i = -1;
		while (++i < cylinders->length)
			new[i] = cylinders->cylinders[i];
		free(cylinders->cylinders);
		cylinders->cylinders = new;
	}
	cylinders->cylinders[cylinders->length] = cylinder;
	++cylinders->length;
	return (SUCCESS);
}
