/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:35:55 by xwu               #+#    #+#             */
/*   Updated: 2025/08/15 19:19:22 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

int	key_hook(int keycode, t_ins *par)
{
	if (keycode == XK_Escape)
	{
		write(1, "Program exited successfully\n", 29);
		exit (0);
	}
	if (keycode)
	return (0);
}

int destroy_win(t_ins *par)
{
	write(1, "Program exited successfully\n", 29);
	exit (0);
}
