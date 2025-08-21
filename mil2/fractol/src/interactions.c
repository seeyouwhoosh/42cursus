/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:04:58 by xwu               #+#    #+#             */
/*   Updated: 2025/08/21 16:26:41 by xwu              ###   ########.fr       */
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
	return (0);
}

int	key_press(int keycode, t_ins *ins)
{
	if (keycode == XK_Escape)
		destroy_win(ins);
	if (keycode == XK_Left || keycode == XK_a || keycode == XK_A)
		ins->key_left = 1;
	if (keycode == XK_Right || keycode == XK_d || keycode == XK_D)
		ins->key_right = 1;
	if (keycode == XK_Up || keycode == XK_w || keycode == XK_W)
		ins->key_up = 1;
	if (keycode == XK_Down || keycode == XK_s || keycode == XK_S)
		ins->key_down = 1;
	if (keycode == XK_plus)
		ins->zoom_in = 1;
	if (keycode == XK_minus)
		ins->zoom_out = 1;
	return (0);
}

int	key_release(int keycode, t_ins *ins)
{
	if (keycode == XK_Left || keycode == XK_a || keycode == XK_A)
		ins->key_left = 0;
	if (keycode == XK_Right || keycode == XK_d || keycode == XK_D)
		ins->key_right = 0;
	if (keycode == XK_Up || keycode == XK_w || keycode == XK_W)
		ins->key_up = 0;
	if (keycode == XK_Down || keycode == XK_s || keycode == XK_S)
		ins->key_down = 0;
	if (keycode == XK_plus)
		ins->zoom_in = 0;
	if (keycode == XK_minus)
		ins->zoom_out = 0;
	return (0);
}

int	loop_hook(t_ins *ins)
{
	double	speed;

	speed = 10 / ins->f.zoom;
	if (ins->key_up)
		ins->f.offset_y -= speed;
	if (ins->key_left)
		ins->f.offset_x -= speed;
	if (ins->key_down)
		ins->f.offset_y += speed;
	if (ins->key_right)
		ins->f.offset_x += speed;
		if (ins->zoom_in)
		ins->f.zoom *= 1.04;
	if (ins->zoom_out)
		ins->f.zoom /= 1.04;
	ins->f.max_iter = 40 + (int)(log10(ins->f.zoom) * 10);
	if (ins->key_left || ins->key_right || ins->key_up || ins->key_down || ins->zoom_in || ins->zoom_out)
	{
		fractal(&ins->img, &ins->f);
		mlx_put_image_to_window(ins->mlx, ins->win, ins->img.img, 0, 0);
	}
	return (0);
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
	ins->f.max_iter = 40 + (unsigned int)(log10(ins->f.zoom) * 10);
	ins->f.offset_x = m_re - (x - WIDTH / 2.0) / ins->f.zoom;
	ins->f.offset_y = m_im - (y - HEIGHT / 2.0) / ins->f.zoom;
	fractal(&ins->img, &ins->f);
	mlx_put_image_to_window(ins->mlx, ins->win, ins->img.img, 0, 0);
	return (0);
}
