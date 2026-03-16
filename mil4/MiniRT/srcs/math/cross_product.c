/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:05:02 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 19:41:32 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vec_prod(t_vec a, t_vec b)
{
	t_vec	new;

	new.x = a.y * b.z - a.z * b.y;
	new.y = a.z * b.x - a.x * b.z;
	new.z = a.x * b.y - a.y * b.x;
	return (new);
}

double	dot_prod(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	points_vec(t_vec a, t_vec b)
{
	t_vec	new;

	new.x = b.x - a.x;
	new.y = b.y - a.y;
	new.z = b.z - a.z;
	return (new);
}

t_vec	new_vec(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec	get_right(t_vec a)
{
	t_vec	worldup;

	worldup.x = 0;
	worldup.y = 1;
	worldup.z = 0;
	if (fabs(fabs(dot_prod(worldup, a)) - 1.0) < TOL)
		worldup.z = 1;
	worldup = vec_prod(worldup, a);
	normalise(&worldup);
	return (worldup);
}
