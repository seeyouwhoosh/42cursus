/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_move2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:45:39 by xwu               #+#    #+#             */
/*   Updated: 2026/03/14 15:45:39 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	say_mode(t_miniRT *rt)
{
	int	mode;

	mode = rt->mouse_select.x;
	ft_putstr_fd("Resizing cylinder by ", 1);
	if (mode == 1)
		ft_putendl_fd("Diameter", 1);
	else if (mode == 2)
		ft_putendl_fd("Height", 1);
	ft_putendl_fd("To change modes, press the desired mode\n[1] By \
diameter\n[2] By height", 1);
	rt->mouse_select.y = 0;
}

void	size_up_figure(t_obj type, void *object, t_miniRT *rt)
{
	int	mode;

	mode = rt->mouse_select.x;
	if (type == SPHERE)
		resize_sphere_plus(object);
	else if (type == CYL_BODY || type == CYL_CAP)
	{
		if (rt->mouse_select.y)
			say_mode(rt);
		resize_cylinder_plus(object, mode);
	}
	else if (type == LIGHT)
		resize_light_plus(object, 0);
	else
		return ;
}

void	size_down_figure(t_obj type, void *object, t_miniRT *rt)
{
	int	mode;

	mode = rt->mouse_select.x;
	if (type == SPHERE)
		resize_sphere_minus(object);
	else if (type == CYL_BODY || type == CYL_CAP)
	{
		if (rt->mouse_select.y)
			say_mode(rt);
		resize_cylinder_minus(object, mode);
	}
	else if (type == LIGHT)
		resize_light_minus(object, 0);
	else
		return ;
}
