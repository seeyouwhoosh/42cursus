/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:03:17 by xwu               #+#    #+#             */
/*   Updated: 2025/08/18 18:03:17 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal(t_data *img, t_fractal *f)
{
	unsigned int	px;
	unsigned int	py;

	py = -1;
	while (++py < HEIGHT)
	{
		px = -1;
		while (++px < WIDTH)
			f->draw_fractal(img, f, px, py);
	}
}

void	draw_mandelbrot(t_data *img, t_fractal *f, double px, double py)
{
	unsigned int	iter;
	double			tmp;

	f->z_re = 0;
	f->z_im = 0;
	f->re = (px - WIDTH / 2.0) / f->zoom + f->offset_x;
	f->im = (py - HEIGHT / 2.0) / f->zoom + f->offset_y;
	iter = 0;
	while (iter < f->max_iter && (f->z_re * f->z_re + f->z_im * f->z_im) < 4)
	{
		tmp = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->re;
		f->z_im = 2 * f->z_re * f->z_im + f->im;
		f->z_re = tmp;
		iter++;
	}
	if (iter == f->max_iter)
		mmlx_pixel_put(img, px, py, 0x00000000);
	else
		mmlx_pixel_put(img, px, py, psychedelic_color(iter, f->max_iter));
}

void	draw_julia(t_data *img, t_fractal *f, double px, double py)
{
	unsigned int	iter;
	double			tmp;

	f->z_re = (px - WIDTH / 2.0) / f->zoom + f->offset_x;
	f->z_im = (py - HEIGHT / 2.0) / f->zoom + f->offset_y;
	iter = 0;
	while (iter < f->max_iter && (f->z_re * f->z_re + f->z_im * f->z_im) < 4)
	{
		tmp = (f->z_re * f->z_re) - (f->z_im * f->z_im) + f->re;
		f->z_im = 2 * f->z_re * f->z_im + f->im;
		f->z_re = tmp;
		iter++;
	}
	if (iter == f->max_iter)
		mmlx_pixel_put(img, px, py, 0x00000000);
	else
		mmlx_pixel_put(img, px, py, psychedelic_color(iter, f->max_iter));
}


void	fractal_init(t_fractal *f)
{
	f->offset_y = 0;
	f->offset_x = 0;
	f->zoom = 400;
	f->max_iter = 40;
	f->z_re = 0;
	f->z_im = 0;
	if (f->draw_fractal == draw_mandelbrot)
		f->offset_x = -0.5;
}
