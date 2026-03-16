/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:16:27 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/15 00:20:42 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	apply(t_camera *cam, t_vec coefs)
{
	cam->dir = rotate_x(cam->dir, coefs.x);
	cam->right = rotate_x(cam->right, coefs.x);
	cam->up = rotate_x(cam->up, coefs.x);
	cam->dir = rotate_y(cam->dir, coefs.y);
	cam->right = rotate_y(cam->right, coefs.y);
	cam->up = rotate_y(cam->up, coefs.y);
	cam->dir = rotate_z(cam->dir, coefs.z);
	cam->right = rotate_z(cam->right, coefs.z);
	cam->up = rotate_z(cam->up, coefs.z);
}

int	rotate_cam(t_camera *camera, t_miniRT *rt)
{
	t_vec	coefs;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x axis", 1);
	if (ask_factor(&(coefs.x)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the y axis", 1);
	if (ask_factor(&(coefs.y)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the z axis", 1);
	if (ask_factor(&(coefs.z)))
		return (MALLOC);
	apply(camera, coefs);
	normalise(&(camera->dir));
	normalise(&(camera->up));
	normalise(&(camera->right));
	return (SUCCESS);
}

int	rotate_cam_cam(t_camera *camera, t_miniRT *rt)
{
	t_vec	coefs;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.x)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the y\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.y)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the z\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.z)))
		return (MALLOC);
	apply_cam(camera, coefs);
	normalise(&(camera->dir));
	normalise(&(camera->up));
	normalise(&(camera->right));
	return (SUCCESS);
}

int	rotate_plane(t_plane *plane, t_miniRT *rt)
{
	double	x;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_x(plane->dir, x);
	ft_putendl_fd("Asking for rotation angle over the y axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_y(new_dir, x);
	ft_putendl_fd("Asking for rotation angle over the z axis\n", 1);
	if (ask_factor(&x))
		return (MALLOC);
	new_dir = rotate_z(new_dir, x);
	plane->dir = new_dir;
	normalise(&new_dir);
	return (SUCCESS);
}

int	rotate_plane_cam(t_plane *plane, t_miniRT *rt)
{
	t_vec	coefs;
	t_vec	new_dir;

	(void)rt;
	ft_putendl_fd("Asking for rotation angle over the x\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.x)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the y\
		 axis of the camra\n", 1);
	if (ask_factor(&(coefs.y)))
		return (MALLOC);
	ft_putendl_fd("Asking for rotation angle over the z\
		 axis of the camera\n", 1);
	if (ask_factor(&(coefs.z)))
		return (MALLOC);
	new_dir = rotate_dir(plane->dir, rt->camera, coefs);
	plane->dir = new_dir;
	return (SUCCESS);
}
