/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vecs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 19:48:39 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/12 22:53:57 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_spheres(t_miniRT *rt, int *flag)
{
	rt->spheres = ft_calloc(sizeof(t_spheres), 1);
	if (!rt->spheres)
	{
		*flag = MALLOC;
		return ;
	}
	rt->spheres->capacity = CAPACITY;
	rt->spheres->length = 0;
	rt->spheres->spheres = ft_calloc(sizeof(t_cylinder), CAPACITY);
	if (!rt->spheres->spheres)
		*flag = MALLOC;
}

void	init_cylinders(t_miniRT *rt, int *flag)
{
	rt->cylinders = ft_calloc(sizeof(t_cylinders), 1);
	if (!rt->cylinders)
	{
		*flag = MALLOC;
		return ;
	}
	rt->cylinders->capacity = CAPACITY;
	rt->cylinders->length = 0;
	rt->cylinders->cylinders = ft_calloc(sizeof(t_cylinder), CAPACITY);
	if (!rt->cylinders->cylinders)
		*flag = MALLOC;
}

void	init_planes(t_miniRT *rt, int *flag)
{
	rt->planes = ft_calloc(sizeof(t_planes), 1);
	if (!rt->planes)
	{
		*flag = MALLOC;
		return ;
	}
	rt->planes->capacity = CAPACITY;
	rt->planes->length = 0;
	rt->planes->planes = ft_calloc(sizeof(t_cylinder), CAPACITY);
	if (!rt->planes->planes)
		*flag = MALLOC;
}

int	sanitize_line(char *line)
{
	int	i;

	if ((line[0] && line[0] == '\n')
		|| (line[0] && line[0] == '\r' && line[1] && line[1] == '\n'))
		return (0);
	if ((line[0] && line[0] == '#')
		|| (line[0] && line[0] == '/' && line[1] && line[1] == '/'))
		return (0);
	i = -1;
	while (line && line[++i])
		if (line[i] == '\t' || line[i] == '\n' || line[i] == '\r')
			line[i] = ' ';
	return (1);
}
