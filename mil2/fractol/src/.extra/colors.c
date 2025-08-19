/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/13 14:52:53 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void	gradient_test(t_data *img)
{
	for (int j = 0; j < HEIGHT; j++)
	{
		int green = 255 - (j * 30 / HEIGHT);
		int blue = 201 + (j * 44 / HEIGHT);
		int color = 186 << 16 | (green << 8) | blue;
		for (int i = 0; i < WIDTH; i++)
			mmlx_pixel_put(img, i, j, color);
	}
}
