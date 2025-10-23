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

int	psychedelic_color(unsigned int iter, unsigned int max_iter)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	double			t;

	t = (double)iter / (double)max_iter;
	r = (unsigned int)(sin((t + 0.000) * M_PI * 2) * 127 + 128);
	g = (unsigned int)(sin((t + 0.333) * M_PI * 2) * 127 + 128);
	b = (unsigned int)(sin((t + 0.666) * M_PI * 2) * 127 + 128);
	r = (r + 255) / 2;
	g = (g + 255) / 2;
	b = (b + 255) / 2;
	return ((r << 16) | (g << 8) | b);
}
