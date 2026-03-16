/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:35:06 by xwu               #+#    #+#             */
/*   Updated: 2026/03/14 02:02:08 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mouse_hook(int key, int x, int y, t_miniRT *rt)
{
	t_obj	type;
	void	*object;

	if (key == LEFT_CLICK)
	{
		type = rt->screen->screen[WIDTH * y + x].type;
		object = rt->screen->screen[WIDTH * y + x].obj;
		if (type == NONE)
			return (0);
		rt->mouse_select.obj = object;
		rt->mouse_select.type = type;
		current_obj_msg(type);
	}
	else if (key == RIGHT_CLICK)
	{
		rt->mouse_select.obj = NULL;
		rt->mouse_select.type = NONE;
		ft_putendl_fd("Object deselected", 1);
	}
	return (0);
}
