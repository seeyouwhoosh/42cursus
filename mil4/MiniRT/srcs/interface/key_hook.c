/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:31:53 by xwu               #+#    #+#             */
/*   Updated: 2026/03/11 19:31:53 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* KEY SHORTCUTS
- [ESC]	close program
- [BackSpace]	deselect figure
- [l or L]	select light
- [p or P] && [obj selected]	move obj (absolute)
- [m] && [obj selected]	move obj (relative)
- [M] && [obj selected]	move obj (relative to camera)
- [r] && [obj selected]	rotate obj (absolute)
- [R] && [obj selected] rotate obj (relative to camera)
- [f] && [obj selected]	resize obj
- [+] && [obj selected]	resize (+) obj
- [-] && [obj selected]	resize (-) obj
- [m]	move obj (relative)
- [p]	move camera (absolute)
- [M]	move camera (relative to camera)
- [r]	rotate camera (absolute)
- [R]	rotate camera (relative to camera)
*/

/* 
int	rotate_cam_keys(int keycode, t_miniRT *rt)
{
	t_vec	coefs;
	t_vec	new_dir;

	coefs = rt->camera->dir;
	if (ft_tolower(keycode) == XK_a)
		
	else if (ft_tolower(keycode) == XK_d)
	else if (ft_tolower(keycode) == XK_w)
	else if (ft_tolower(keycode) == XK_s)
	//rotar respecto a la base de la cámara y establecer nueva base
}*/

static int	camera_changes(int keycode, t_miniRT *rt)
{
	if (keycode == XK_m)
		move_cam(rt->camera, rt);
	else if (keycode == XK_M)
		move_cam_from(rt->camera, rt);
	else if (ft_tolower(keycode) == XK_p)
		place_cam(rt->camera, rt);
	else if (keycode == XK_f)
		ask_fov(&rt->camera->fov);
	else if (keycode == XK_F)
		ask_change_fov(&rt->camera->fov);
	else if (keycode == XK_r)
	{
		ft_putendl_fd("Rotating camera", 1);
		rotate_cam(rt->camera, rt);
	}
	else if (keycode == XK_R)
	{
		ft_putendl_fd("Rotating camera in relation to camera", 1);
		rotate_cam_cam(rt->camera, rt);
	}
	else
		return (0);
	return (1);
}

static int	object_changes(int keycode, t_miniRT *rt)
{
	if (rt->mouse_select.type == NONE)
		return (0);
	if (keycode == XK_m)
		move_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (keycode == XK_M)
		move_figure_from(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (ft_tolower(keycode) == XK_p)
		place_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (ft_tolower(keycode) == XK_f)
		resize_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (ft_tolower(keycode) == XK_r)
		rotate_figure(rt->mouse_select.type, rt->mouse_select.obj, rt, keycode);
	else if (keycode == XK_plus)
		size_up_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else if (keycode == XK_minus)
		size_down_figure(rt->mouse_select.type, rt->mouse_select.obj, rt);
	else
		return (0);
	return (1);
}

int	misc_keys(int keycode, t_miniRT *rt)
{
	if (keycode == XK_Escape)
		free_all(rt);
	else if (keycode == XK_BackSpace)
	{
		rt->mouse_select.obj = NULL;
		rt->mouse_select.type = NONE;
		ft_putendl_fd("Object deselected", 1);
		return (0);
	}
	else if (ft_tolower(keycode) == XK_l)
	{
		rt->mouse_select.obj = rt->light;
		rt->mouse_select.type = LIGHT;
		current_obj_msg(LIGHT);
	}
	else if ((keycode == XK_1 || keycode == XK_2)
		&& rt->mouse_select.x != keycode - '0')
	{
		rt->mouse_select.x = keycode - '0';
		rt->mouse_select.y = 1;
	}
	else
		return (0);
	return (1);
}

int	camera_move(int keycode, t_miniRT *rt)
{
	if (keycode == XK_Left)
		move_by(&rt->camera->pos, rt->camera->right, -SPEED);
	else if (keycode == XK_Right)
		move_by(&rt->camera->pos, rt->camera->right, SPEED);
	else if (keycode == XK_Up)
		move_by(&rt->camera->pos, rt->camera->up, SPEED);
	else if (keycode == XK_Down)
		move_by(&rt->camera->pos, rt->camera->up, -SPEED);
	else
		return (0);
	return (1);
}

int	key_hook(int keycode, t_miniRT *rt)
{
	rt->mouse_select.t = 0.0;
	if (misc_keys(keycode, rt))
		return (0);
	if (camera_move(keycode, rt)
		|| object_changes(keycode, rt) || camera_changes(keycode, rt))
		rt->mouse_select.t = 1.0;
	if (keycode && rt->mouse_select.t)
	{
		reset_screen(rt);
		loop(rt);
	}
	return (0);
}
