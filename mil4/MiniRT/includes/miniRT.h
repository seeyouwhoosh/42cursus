/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:55:09 by gcassi-d          #+#    #+#             */
/*   Updated: 2026/03/14 19:42:15 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "t_vec.h"
# include <math.h>
# include "ambientlighting.h"
# include "camera.h"
# include "cylinder.h"
# include "light.h"
# include "plane.h"
# include "sphere.h"
# include "libft.h"
# include "mlx.h"
# ifndef __APPLE__
#  include <X11/keysym.h>
# else
#  include "keycodes.h"
#  include <OpenGL/gl.h>
# endif
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600
# define CAPACITY 256
# define PI 3.14159265358979323846
# define PI2 1.57079632679489661923
# define PI4 0.78539816339744830962
# define ROTANG 0.00872664625997164788
# define TOL 0.0001
# define SCALE 1.1
# define FOV 1
# define K 0.032
# define L 0.09
# define C 1.0

enum e_errors
{
	SUCCESS,
	IN_AM,
	FILE_NAME,
	FILE_NOT_FOUND,
	MALLOC,
	UNKNOWN_SPECIFIER,
	WRONG_SPECIFIER,
	MULTIPLE_MANDATORY,
	NO_MANDATORY,
	NO_DIR,
	EMPTY,
};

enum e_mlx_key_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17
};

enum e_mlx_mouse_events
{
	ZERO,
	LEFT_CLICK,
	CENTER_CLICK,
	RIGHT_CLICK,
	SCROLL_UP,
	SCROLL_DOWN,
	SCROLL_LEFT,
	SCROLL_RIGHT
};

typedef enum e_obj
{
	NONE,
	PLANE,
	SPHERE,
	CYL_BODY,
	CYL_CAP,
	LIGHT,
}	t_obj;

typedef struct s_pixel
{
	int		x;
	int		y;
	double	t;
	t_obj	type;
	void	*obj;
}	t_pixel;

typedef struct s_screen
{
	t_pixel	*screen;
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_addr;
	int		endian;
	int		img_length;
	int		bits_per_pixel;
}	t_screen;

typedef struct s_miniRT
{
	t_screen		*screen;
	t_AmbientLight	*ambient_light;
	t_camera		*camera;
	t_cylinders		*cylinders;
	t_light			*light;
	t_planes		*planes;
	t_spheres		*spheres;
	t_pixel			mouse_select;
}	t_miniRT;

/* FREE */
int		free_all(t_miniRT *rt);
void	free_screen(t_screen *screen);
void	free_split(char **split);

/* INIT */
int		init(t_miniRT *rt, char *filename);
void	init_spheres(t_miniRT *rt, int *flag);
void	init_cylinders(t_miniRT *rt, int *flag);
void	init_planes(t_miniRT *rt, int *flag);

/* PARSING */
int		parse(t_miniRT *rt, char *line);
int		parse_camera(t_miniRT *rt, char **split);
int		parse_ambient_lighting(t_miniRT *rt, char **split);
int		parse_light(t_miniRT *rt, char **split);
int		parse_sphere(t_miniRT *rt, char **split);
int		parse_plane(t_miniRT *rt, char **split);
int		parse_cylinder(t_miniRT *rt, char **split);
int		sanitize_line(char *line);

/* UTILS */
void	remove_nl(char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atod(char *str, double *x);
int		ft_ft_atoi(char *str, int *n);
int		is_color(int r, int g, int b);
double	mod(double x, double y, double z);
int		validate_nums(char *nums);
int		validate_dir(double *x, double *y, double *z);
void	reset_screen(t_miniRT *rt);

/* TESTING/ERROR */
void	errormsg(int flag);
void	start(t_miniRT *rt);
void	print_vec(t_vec vec);

/* VECTORS */
int		add_plane(t_planes *planes, t_plane plane);
int		add_sphere(t_spheres *spheres, t_sphere sphere);
int		add_cylinder(t_cylinders *cylinders, t_cylinder cylinder);

/* MOVING */
void	move_figure(t_obj type, void *object, t_miniRT *rt);
void	place_figure(t_obj type, void *object, t_miniRT *rt);
void	move_figure_from(t_obj type, void *object, t_miniRT *rt);
int		move_cam(t_camera *camera, t_miniRT *rt);
int		place_cam(t_camera *camera, t_miniRT *rt);
int		move_cam_from(t_camera *camera, t_miniRT *rt);
int		move_plane(t_plane *plane, t_miniRT *rt);
int		place_plane(t_plane *plane, t_miniRT *rt);
int		move_plane_from(t_plane *plane, t_miniRT *rt);
int		move_cylinder(t_cylinder *cylinder, t_miniRT *rt);
int		place_cylinder(t_cylinder *cylinder, t_miniRT *rt);
int		move_cylinder_from(t_cylinder *cylinder, t_miniRT *rt);
int		move_sphere(t_sphere *sphere, t_miniRT *rt);
int		place_sphere(t_sphere *sphere, t_miniRT *rt);
int		move_sphere_from(t_sphere *sphere, t_miniRT *rt);
int		move_light(t_light *light, t_miniRT *rt);
int		place_light(t_light *light, t_miniRT *rt);
int		move_light_from(t_light *light, t_miniRT *rt);

/* UI */
int		ask_coords(double *x, double *y, double *z);
int		ask_factor(double *x);
int		ask_fov(int *x);
int		ask_change_fov(int *x);
void	write_ask(char *msg, double *x);

/* MATH */
t_vec	vec_prod(t_vec a, t_vec b);
double	dot_prod(t_vec a, t_vec b);
t_vec	new_vec(double x, double y, double z);
t_vec	get_right(t_vec a);
void	translate_base(t_vec *pos, t_camera *cam, t_vec coefs);
void	move_by(t_vec *vec, t_vec dir, double coef);
void	normalise(t_vec *vec);
t_vec	points_vec(t_vec a, t_vec b);
void	update(t_vec *vec, double coef);
t_vec	add(t_vec vec, t_vec vec2);
double	norm(t_vec vec);
t_vec	times(t_vec vec, double coef);

/* RESIZE */
void	resize_figure(t_obj type, void *obj, t_miniRT *rt);
int		resize_sphere(t_sphere *sphere);
int		resize_sphere_plus(t_sphere *sphere);
int		resize_sphere_minus(t_sphere *sphere);
int		resize_cylinder(t_cylinder *cylinder);
int		resize_cylinder_plus(t_cylinder *cylinder, int mode);
int		resize_cylinder_minus(t_cylinder *cylinder, int mode);
int		resize_light(void *light, int ambience);
int		resize_light_plus(void *light, int ambience);
int		resize_light_minus(void *light, int ambience);
void	size_up_figure(t_obj type, void *object, t_miniRT *rt);
void	size_down_figure(t_obj type, void *object, t_miniRT *rt);

/* ROTATE */
t_vec	rotate_x(t_vec vec, double angle);
t_vec	rotate_y(t_vec vec, double angle);
t_vec	rotate_z(t_vec vec, double angle);
t_vec	rotate_dir(t_vec vec, t_camera *camera, t_vec coefs);
t_vec	rotate_axis(t_vec vec, t_vec axis, double c, double s);
void	apply_cam(t_camera *cam, t_vec coefs);
int		rotate_cam_cam(t_camera *camera, t_miniRT *rt);
int		rotate_cam(t_camera *camera, t_miniRT *rt);
void	rotate_figure(t_obj type, void *obj, t_miniRT *rt, int keycode);
int		rotate_plane(t_plane *plane, t_miniRT *rt);
int		rotate_plane_cam(t_plane *plane, t_miniRT *rt);
int		rotate_cylinder(t_cylinder *cylinder, t_miniRT *rt);
int		rotate_cylinder_cam(t_cylinder *cylinder, t_miniRT *rt);

/* MAIN_LOOP */
t_vec	choose_dir(t_pixel *pixel, t_camera *camera);
void	choose_color(t_screen *screen, t_pixel *pixel, t_vec dir, t_miniRT *rt);
int		loop(t_miniRT *rt);
void	paint(t_screen *screen, t_pixel *point, int p);
int		get_col(t_pixel *pixel, double intens);
int		get_cyl_col(t_cylinder *cylinder, double intens);
int		get_sphere_col(t_sphere *sphere, double intens);
int		get_plane_col(t_plane *plane, double intens);
int		intersect_plane(t_plane *plane, t_vec dir,
			t_pixel *pixel, t_vec pos);
int		intersect_sphere(t_sphere *sphere, t_vec dir,
			t_pixel *pixel, t_vec pos);
int		intersect_cylinder(t_cylinder *cylinder, t_vec dir,
			t_pixel *pixel, t_vec pos);
int		loop(t_miniRT *rt);
int		set_cyl_body(t_pixel *px, t_cylinder *cyl, double t);
int		set_cyl_cap(t_pixel *px, t_cylinder *cyl, double t);
int		get_true_col(t_miniRT *rt, t_pixel *px, t_vec vec);
t_vec	get_grad(t_pixel *px, t_camera *cam, t_vec pos);

/* MLX HOOKS */
void	mlx_hooks(t_miniRT *rt);
int		key_hook(int keycode, t_miniRT *rt);
int		mouse_hook(int key, int x, int y, t_miniRT *rt);
int		key_hook(int keycode, t_miniRT *rt);
void	current_obj_msg(t_obj type);

#endif