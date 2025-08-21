/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/17 19:36:02 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mmlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	pixel_to_math(t_point *p)
{
	double	min_re;
	double	max_re;
	double	scr_ratio;
	double	min_im;
	double	max_im;
	
	min_re = -2;
	max_re = 2;
	scr_ratio = HEIGHT/WIDTH;

	min_im = -(max_re-min_re) * scr_ratio;
	max_im = (max_re-min_re) * scr_ratio;

	p->re = min_re + p->x * (max_re-min_re) / WIDTH;
	p->im = min_im + p->y * (max_im-min_im) / HEIGHT;
}

void	math_to_pixel(t_point *p)
{
	;
}

void	graph_data_init(t_data *img)
{
	double	scr_ratio;

	img->min_re = -2;
	img->max_re = 2;
	scr_ratio = HEIGHT/WIDTH;

	img->min_im = -(img->max_re - img->min_re) * scr_ratio;
	img->max_im = (img->max_re - img->min_re) * scr_ratio;
}

void	graph_data_update(t_data *img)
{
	double	scr_ratio;

	scr_ratio = HEIGHT/WIDTH;
	img->min_im = -(img->max_re - img->min_re) * scr_ratio;
	img->max_im = (img->max_re - img->min_re) * scr_ratio;
}