/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/19 14:02:41 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>



int	main(int ac, char **av)
{
	t_ins	ins;

	// Argument management
	manage_args(ac, av, &ins);
	// Inicializing window
	ins.mlx = mlx_init();
	ins.win = mlx_new_window(ins.mlx, WIDTH, HEIGHT, "fract-ol");

	// Inicializing image
	ins.img.img = mlx_new_image(ins.mlx, WIDTH, HEIGHT);
	ins.img.addr = mlx_get_data_addr(ins.img.img, &ins.img.bits_per_pixel, &ins.img.line_length, &ins.img.endian);

	fractal_init(&ins.f);
	fractal(&ins.img, &ins.f);
	mlx_put_image_to_window(ins.mlx, ins.win, ins.img.img, 0, 0);

	// Close window and loop
	mlx_key_hook(ins.win, key_hook, &ins);
	mlx_mouse_hook(ins.win, mouse_hook, &ins);
	mlx_hook(ins.win, ON_DESTROY, 0, destroy_win, &ins);
	mlx_loop(ins.mlx);
	return (0);
}
