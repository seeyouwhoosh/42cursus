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
