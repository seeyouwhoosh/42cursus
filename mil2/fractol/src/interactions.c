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

int	key_hook(int keycode, t_ins *ins)
{
	if (keycode == XK_Escape)
	{
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
	if (keycode == XK_w || keycode == XK_a
		|| keycode == XK_s || keycode == XK_d)
		move(keycode, &ins->f);
	if (keycode == XK_plus || keycode == XK_minus)
		zoom(keycode, &ins->f);
	fractal(&ins->img, &ins->f);
	mlx_put_image_to_window(ins->mlx, ins->win, ins->img.img, 0, 0);
	return (0);
}

void	move(int keycode, t_fractal *f)
{
	if (keycode == XK_w)
		f->offset_y -= 10 / f->zoom;
	if (keycode == XK_a)
		f->offset_x -= 10 / f->zoom;
	if (keycode == XK_s)
		f->offset_y += 10 / f->zoom;
	if (keycode == XK_d)
		f->offset_x += 10 / f->zoom;
}

void	zoom(int keycode, t_fractal *f)
{
	if (keycode == XK_plus)
		f->zoom *= 1.04;
	else if (keycode == XK_minus)
		f->zoom /= 1.04;
	f->max_iter = 40 + (unsigned int)(log10(f->zoom) * 6);
}

int	mouse_hook(int keycode, int x, int y, t_ins *ins)
{
	double	m_re;
	double	m_im;

	m_re = (x - WIDTH / 2.0) / ins->f.zoom + ins->f.offset_x;
	m_im = (y - HEIGHT / 2.0) / ins->f.zoom + ins->f.offset_y;
	if (keycode == ON_MOUSEUP)
		ins->f.zoom /= 1.04;
	if (keycode == ON_MOUSEDOWN)
		ins->f.zoom *= 1.04;
	ins->f.max_iter = 40 + (unsigned int)(log10(ins->f.zoom) * 6);
	ins->f.offset_x = m_re - (x - WIDTH / 2.0) / ins->f.zoom;
	ins->f.offset_y = m_im - (y - HEIGHT / 2.0) / ins->f.zoom;
	fractal(&ins->img, &ins->f);
	mlx_put_image_to_window(ins->mlx, ins->win, ins->img.img, 0, 0);
	return (0);
}

int	psychedelic_color(unsigned int iter, unsigned int max_iter)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	double			t;

	t = (double)iter / (double)max_iter;
	r = (unsigned int)(sin((t + 0.000) * M_PI * 2) * 127 + 128);
	g = (unsigned int)(sin((t + 0.000) * M_PI * 2) * 127 + 128);
	b = (unsigned int)(sin((t + 0.000) * M_PI * 2) * 127 + 128);
	r = (r + 255) / 2;
	g = (g + 255) / 2;
	b = (b + 255) / 2;
	return ((r << 16) | (g << 8) | b);
}
