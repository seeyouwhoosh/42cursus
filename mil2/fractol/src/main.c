/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/19 13:00:41 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

int	main(void)
{
	t_ins		ins;

	// Inicializing window
	ins.mlx = mlx_init();
	ins.win = mlx_new_window(ins.mlx, WIDTH, HEIGHT, "Window");

	// Inicializing image
	ins.img.img = mlx_new_image(ins.mlx, WIDTH, HEIGHT);
	ins.img.addr = mlx_get_data_addr(ins.img.img, &ins.img.bits_per_pixel, &ins.img.line_length, &ins.img.endian);

	// Fractal
	fractal_init(&ins.f);
	mandelbrot(&ins.img, &ins.f);
	mlx_put_image_to_window(ins.mlx, ins.win, ins.img.img, 0, 0);

	// Close window and loop
	mlx_key_hook(ins.win, key_hook, &ins);
	mlx_hook(ins.win, ON_DESTROY, 0, destroy_win, NULL);
	mlx_loop(ins.mlx);
	return (0);
}

void move(int keycode, t_fractal *f)
{
	if (keycode == XK_w)
		f->offset_y -= 10 / f->zoom;
	if (keycode == XK_a)
		f->offset_x -= 10 / f->zoom;
	if (keycode == XK_s)
		f->offset_y += 10 / f->zoom;
	if (keycode == XK_d)
		f->offset_x += 10 / f->zoom;
	if (keycode == XK_space)
	{
		f->offset_y = 0;
		f->offset_x = -0.5;
		f->zoom = 200;
	}
}

void zoom(int keycode, t_fractal *f)
{
	if (keycode == XK_plus)
	{
		f->zoom *= 1.04;
		f->max_iter += (unsigned int) log10(f->zoom) / 4;
	}
	else if (keycode == XK_minus)
	{
		f->zoom /= 1.04;
		f->max_iter -= (unsigned int) log10(f->zoom) / 4;
	}
}