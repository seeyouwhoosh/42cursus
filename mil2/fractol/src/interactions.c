/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:35:55 by xwu               #+#    #+#             */
/*   Updated: 2025/08/18 14:03:21 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		write(1, "Program exited successfully\n", 29);
		exit (0);
	}
/* 	if (keycode == XK_plus || keycode == XK_minus)
		zoom(keycode, data);
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d)
		move(keycode, data); */
	return (0);
}

void zoom(int keycode, t_data *data)
{
	if (keycode == XK_plus)
	{
		data->min_re *= 1.05;
		data->max_re *= 1.05;
	}
	else if (keycode == XK_minus)
	{
		data->min_re *= 0.95;
		data->max_re *= 0.95;
	}
	graph_data_update(data);
}

void move(int keycode, t_data *data)
{
	if (keycode == XK_w);
	if (keycode == XK_a);
	if (keycode == XK_s);
	if (keycode == XK_d);
}

int destroy_win(t_ins *par)
{
	write(1, "Program exited successfully\n", 29);
	exit (0);
}
