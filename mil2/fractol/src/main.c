/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/15 20:43:55 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	gradient_test(t_data *img)
{
	for (int j = 0; j < HEIGHT; j++)
	{
		int green = 255 - (j * 30 / HEIGHT);
		int blue = 201 + (j * 44 / HEIGHT);
		int color = 186 << 16 | (green << 8) | blue;
		for (int i = 0; i < WIDTH; i++)
			mmlx_pixel_put(img, i, j, color);
	}
}

void	draw_circle(t_data *img, int radius, t_point *center)
{
	int color = 0xFF0000;
	t_point	c;
	if (!center)
	{
		c.x = WIDTH / 2;
		c.y = HEIGHT / 2;
		center = &c;
	}
	for (int j = -radius; j <= radius; j++)
	{
		for (int i = -radius; i <= radius; i++)
		{
			if (i * i + j * j <= radius * radius)
				mmlx_pixel_put(img, center->x + i, center->y + j, color);
		}
	}
}


int	main(void)
{
	t_ins	ins;
	t_data	img;

	ins.mlx = mlx_init();
	ins.win = mlx_new_window(ins.mlx, WIDTH, HEIGHT, "Window");

	img.img = mlx_new_image(ins.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (!img.addr)
		return (1);
	draw_circle(&img, 50, NULL);
	mlx_put_image_to_window(ins.mlx, ins.win, img.img, 0, 0);

	mlx_key_hook(ins.win, key_hook, &ins);
	mlx_hook(ins.win, ON_DESTROY, 0, destroy_win, NULL);
	mlx_loop(ins.mlx);
	return (0);
}
