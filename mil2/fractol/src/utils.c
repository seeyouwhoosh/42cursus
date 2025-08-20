/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:04:58 by xwu               #+#    #+#             */
/*   Updated: 2025/08/18 18:04:58 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

void	mmlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

void	manage_args(int ac, char **av, t_ins *ins)
{
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
		ins->f.re = 0.355;
		ins->f.im = 0.113;
	}
	else
	{
		printf("\e[1;1m Non valid parameters. You may choose from the following:\e[0m\
\n [1] \e[1;34mmandelbrot \e[0m\
\n [2] \e[1;34mjulia \e[0m\e[0;30m[real_part: 0.355] [imaginary_part: 0.113]\n");
		exit(1);
	}
}
