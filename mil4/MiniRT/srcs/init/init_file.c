/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 18:55:16 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 14:11:00 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	init_camera(t_miniRT *rt)
{
	rt->camera = ft_calloc(sizeof(t_camera), 1);
	if (!rt->camera)
		return (MALLOC);
	rt->camera->isdef = 0;
	return (SUCCESS);
}

static int	init_screen(t_screen *screen)
{
	screen->screen = ft_calloc(sizeof(t_pixel), WIDTH * HEIGHT);
	if (!screen)
		return (MALLOC);
	screen->mlx = mlx_init();
	if (!screen->mlx)
		return (MALLOC);
	screen->window = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "BALLS");
	if (!screen->window)
	{
		screen->img_addr = NULL;
		screen->img = NULL;
		return (MALLOC);
	}
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	if (!screen->img)
	{
		screen->img_addr = NULL;
		return (MALLOC);
	}
	screen->img_addr = mlx_get_data_addr(screen->img, &(screen->bits_per_pixel),
			&(screen->img_length), &(screen->endian));
	if (!screen->img_addr)
		return (MALLOC);
	return (SUCCESS);
}

static void	init_screen2(t_screen *screen)
{
	size_t	i;
	size_t	j;
	size_t	pos;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			pos = j * WIDTH + i;
			screen->screen[pos].type = NONE;
			screen->screen[pos].obj = NULL;
			screen->screen[pos].x = i;
			screen->screen[pos].y = j;
			screen->screen[pos].t = INFINITY;
		}
	}
}

static int	init2(t_miniRT *rt, int flag, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FILE_NOT_FOUND);
	line = get_next_line(fd);
	if (!line)
		return (EMPTY);
	while (line)
	{
		if (sanitize_line(line))
			flag = parse(rt, line);
		else
			flag = 0;
		free(line);
		if (flag)
			return (flag);
		line = get_next_line(fd);
	}
	if (!rt->camera->isdef || !rt->light->isdef
		|| !rt->ambient_light->isdef)
		return (NO_MANDATORY);
	return (SUCCESS);
}

int	init(t_miniRT *rt, char *filename)
{
	int	flag;

	flag = SUCCESS;
	init_cylinders(rt, &flag);
	init_planes(rt, &flag);
	init_spheres(rt, &flag);
	rt->screen = ft_calloc(sizeof(t_screen), 1);
	if (!rt->screen)
		return (MALLOC);
	if (init_screen(rt->screen))
		return (MALLOC);
	init_screen2(rt->screen);
	rt->light = ft_calloc(sizeof(t_light), 1);
	if (!rt->light)
		return (MALLOC);
	rt->light->isdef = 0;
	rt->ambient_light = ft_calloc(sizeof(t_AmbientLight), 1);
	if (!rt->ambient_light || init_camera(rt))
		return (MALLOC);
	rt->ambient_light->isdef = 0;
	if (flag)
		return (flag);
	return (init2(rt, flag, filename));
}
