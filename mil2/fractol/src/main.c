/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/23 21:40:22 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_ins	ins;

	manage_args(ac, av, &ins);
	ins.mlx = mlx_init();
	ins.win = mlx_new_window(ins.mlx, WIDTH, HEIGHT, "fract-ol");
	ins.img.img = mlx_new_image(ins.mlx, WIDTH, HEIGHT);
	ins.img.addr = mlx_get_data_addr(ins.img.img, &ins.img.bits_per_pixel,
			&ins.img.line_length, &ins.img.endian);
	fractal_init(&ins);
	fractal(&ins.img, &ins.f);
	mlx_put_image_to_window(ins.mlx, ins.win, ins.img.img, 0, 0);
	mlx_hook(ins.win, ON_KEYDOWN, 1L << 0, key_press, &ins);
	mlx_hook(ins.win, ON_KEYUP, 1L << 1, key_release, &ins);
	mlx_loop_hook(ins.mlx, loop_hook, &ins);
	mlx_mouse_hook(ins.win, mouse_hook, &ins);
	mlx_hook(ins.win, ON_DESTROY, 0, destroy_win, &ins);
	mlx_loop(ins.mlx);
	return (0);
}
