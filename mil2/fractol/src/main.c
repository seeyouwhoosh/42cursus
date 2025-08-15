/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/13 14:52:53 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

/* Got a function to redirect keys.  Although better if it's not simultaneous */
int	key_hook(int keycode, t_ins *ins)
{
	if (keycode == XK_Escape)
		mlx_destroy_window(ins->mlx, ins->win);
	return (0);
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
	mlx_key_hook(ins.win, key_hook, &ins);
	
	gradient_test(&img);
	mlx_put_image_to_window(ins.mlx, ins.win, img.img, 0, 0);
	
	mlx_loop(ins.mlx);
	return (0);
}
