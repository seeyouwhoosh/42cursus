/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/10/23 23:57:35 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_win(t_ins *ins)
{
	if (!ins)
		exit(0);
	if (ins->img.img)
		mlx_destroy_image(ins->mlx, ins->img.img);
	if (ins->win)
		mlx_destroy_window(ins->mlx, ins->win);
	if (ins->mlx)
	{
		mlx_destroy_display(ins->mlx);
		free(ins->mlx);
	}
	write(1, "Program exited successfully\n", 29);
	exit (0);
}

void	error_exit(void)
{
	char	*msg;
	msg = "Non valid parameters. You may choose from the following:\n[1] \
mandelbrot\n[2] julia [real_part: 0.355] [imaginary_part: 0.113]\n";
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	manage_args(int ac, char **av, t_ins *ins)
{
	char	*erptr;

	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot") || ft_atoi(av[1]) == 1))
		ins->f.draw_fractal = draw_mandelbrot;
	else if (ac == 2 && (!ft_strcmp(av[1], "julia") || ft_atoi(av[1]) == 2))
	{
		ins->f.draw_fractal = draw_julia;
		ins->f.re = 0.355;
		ins->f.im = 0.113;
	}
	else if (ac == 4 && (!ft_strcmp(av[1], "julia") || ft_atoi(av[1]) == 2))
	{
		ins->f.draw_fractal = draw_julia;
		ins->f.re = ft_strtod(av[2], &erptr);
		if (*erptr)
			error_exit();
		ins->f.im = ft_strtod(av[3], &erptr);
		if (*erptr)
			error_exit();
	}
	else
		error_exit();
}

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
	mlx_mouse_hook(ins.win, mouse_hook, &ins);
	mlx_hook(ins.win, ON_KEYDOWN, 1L << 0, key_hook, &ins);
	mlx_hook(ins.win, ON_DESTROY, 0, destroy_win, &ins);
	mlx_loop(ins.mlx);
	return (0);
}
