/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:24:49 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 19:44:04 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	norm(t_vec vec)
{
	return (sqrt(mod(vec.x, vec.y, vec.z)));
}

t_vec	times(t_vec vec, double coef)
{
	t_vec	new;

	new.x = vec.x * coef;
	new.y = vec.y * coef;
	new.z = vec.z * coef;
	return (new);
}

t_vec	rotate_axis(t_vec vec, t_vec axis, double c, double s)
{
	t_vec	new;

	new = times(vec, c);
	new = add(new, times(vec_prod(axis, vec), s));
	new = add(new, (times(axis, (1 - c) * dot_prod(vec, axis))));
	return (new);
}
