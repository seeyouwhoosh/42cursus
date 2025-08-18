/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/18 18:32:26 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_ins	ins;
	t_data	img;

	// Inicializing window
	ins.mlx = mlx_init();
	ins.win = mlx_new_window(ins.mlx, WIDTH, HEIGHT, "Window");

	// Inicializing image
	img.img = mlx_new_image(ins.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	unsigned int	px = 0;
	unsigned int	py = 0;
	while (py < HEIGHT)
	{
		px = 0;
		while (px < WIDTH)
		{
			double	re;
			double	im;
			
			double	offset_y = 0;
			double	offset_x = -0.5;
			double	zoom = 200;
			
			re = (px - WIDTH/2.0) / zoom + offset_x;
			im = (py - HEIGHT/2.0) / zoom + offset_y;

			unsigned int	max_iter = 250;
			unsigned int	iter = 0;
			
			double	z_re = 0;
			double	z_im = 0;
			double	tmp;
			
			while (iter < max_iter && (z_re * z_re + z_im * z_im) < 4)
			{
				tmp = (z_re * z_re) - (z_im * z_im) + re;
				z_im = 2 * z_re * z_im + im;
				z_re = tmp;
				iter++;
			}
			if (iter == max_iter)
				mmlx_pixel_put(&img, px, py, 0x00000000);
			else
				mmlx_pixel_put(&img, px, py, 0x00000000 | iter * 6);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(ins.mlx, ins.win, img.img, 0, 0);

	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	// Close window and loop
	mlx_key_hook(ins.win, key_hook, &ins);
	mlx_hook(ins.win, ON_DESTROY, 0, destroy_win, NULL);
	mlx_loop(ins.mlx);
	return (0);
}
