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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		write(1, "Program exited successfully\n", 29);
		exit (0);
	}
	return (0);
}
