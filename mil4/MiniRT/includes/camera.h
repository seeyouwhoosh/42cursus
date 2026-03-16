/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:45:11 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 10:59:13 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# define SPEED 1

/* FOV of 0 doesn't make any sense, won't be allowed */
typedef struct s_camera
{
	t_vec	pos;
	t_vec	dir;
	t_vec	right;
	t_vec	up;
	int		fov;
	char	isdef;
	double	f;
}	t_camera;

#endif
