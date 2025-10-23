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

int	key_hook(int keycode, t_ins *ins)
{
	if (keycode == XK_Escape)
		destroy_win(ins);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_ins *ins)
{
	(void)x;
	(void)y;
	if (keycode == ON_MOUSEUP)
		ins->f.zoom /= 1.04;
	if (keycode == ON_MOUSEDOWN)
		ins->f.zoom *= 1.04;
	ins->f.max_iter = 40 + (unsigned int)(log10(ins->f.zoom) * 10);
	fractal(&ins->img, &ins->f);
	mlx_put_image_to_window(ins->mlx, ins->win, ins->img.img, 0, 0);
	return (0);
}
