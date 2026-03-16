/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:24:00 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 18:22:42 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_vec(t_vec vec)
{
	printf("%lf %lf %lf\n", vec.x, vec.y, vec.z);
}

void	start(t_miniRT *rt)
{
	print_vec(rt->camera->right);
	print_vec(rt->camera->dir);
	print_vec(rt->camera->up);
	loop(rt);
	mlx_hooks(rt);
}
