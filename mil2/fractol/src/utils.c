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

/* USABLE FUNCTIONS */

void	mmlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int destroy_win(t_ins *par)
{
	write(1, "Program exited successfully\n", 29);
	exit (0);
}

int	key_hook(int keycode, t_ins *ins)
{
	if (keycode == XK_Escape)
	{
		write(1, "Program exited successfully\n", 29);
		exit (0);
	}
 	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d)
		move(keycode, &ins->f);
	if (keycode == XK_plus || keycode == XK_minus)
		zoom(keycode, &ins->f);
	mandelbrot(&ins->img, &ins->f);
	mlx_put_image_to_window(ins->mlx, ins->win, ins->img.img, 0, 0);
	return (0);
}
