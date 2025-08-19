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

void	static_mandelbrot(t_data *img)
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	
	double	scr_ratio = HEIGHT/WIDTH;
	min_re = -2.2;
	max_re = 0.75;
	min_im = -1.2; // -(max_re - min_re) * scr_ratio;
	max_im = 1.2; // (max_re - min_re) * scr_ratio;

	unsigned int	px = 0;
	unsigned int	py = 0;
	while (py < HEIGHT)
	{
		px = 0;
		while (px < WIDTH)
		{
			double	re;
			double	im;

			double	offset_y = 0;
			double	offset_x = 0;

			re = min_re + px * (max_re-min_re) / WIDTH;
			im = min_im + py * (max_im-min_im) / HEIGHT;

			unsigned int	max_iter = 250;
			unsigned int	iter = 0;
			
			double	z_re = 0;
			double	z_im = 0;
			double	tmp;
			
			while (iter < max_iter && (z_re * z_re + z_im * z_im) < 4)
			{
				tmp = (z_re * z_re) - (z_im * z_im) + re;
				z_im = 2 * z_re * z_im + im;
				z_re = tmp;
				iter++;
			}
			if (iter == max_iter)
				mmlx_pixel_put(img, px, py, 0x00000000);
			else
				mmlx_pixel_put(img, px, py, 0x00000000 | iter * 6);
			px++;
		}
		py++;
	}
}

void	mandelbrot(t_data *img, t_fractal *f)
{
	unsigned int	px;
	unsigned int	py;

	py = -1;
	while (++py < HEIGHT)
	{
		px = -1;
		while (++px < WIDTH)
			draw_mandelbrot(img, f, px, py);
	}
}

void	draw_mandelbrot(t_data *img, t_fractal *f, double px, double py)
{
	unsigned int	iter;
	double	tmp;
	
	f->z_re = 0;
	f->z_im = 0;
	f->re = (px - WIDTH/2.0) / f->zoom + f->offset_x;
	f->im = (py - HEIGHT/2.0) / f->zoom + f->offset_y;
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
		mmlx_pixel_put(img, px, py, 0x00000000 | iter * 6);
}

void fractal_init(t_fractal *f)
{
	f->offset_y = 0;
	f->offset_x = -0.5;
	f->zoom = 200;
	f->max_iter = 50;
	f->z_re = 0;
	f->z_im = 0;
}
