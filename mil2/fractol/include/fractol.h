/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/24 12:46:55 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# ifndef WIDTH
#  define WIDTH 800
# endif // WIDTH
# ifndef HEIGHT
#  define HEIGHT 600
# endif // HEIGHT
# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif // M_PI

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_fractal
{
	double			offset_y;
	double			offset_x;
	double			zoom;
	unsigned int	max_iter;
	double			re;
	double			im;
	double			z_re;
	double			z_im;
	void			(*draw_fractal)(t_data *,
			struct s_fractal *, double, double);
}					t_fractal;

typedef struct s_ins
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_fractal	f;
	short		key_up;
	short		key_down;
	short		key_left;
	short		key_right;
	short		zoom_in;
	short		zoom_out;
}				t_ins;

/* PROGRAM UTILITIES */

/* Manages parameters received, updates needed function in t_fractal structure.
If not valid parameters received, display message */
void	manage_args(int ac, char **av, t_ins *ins);

/* A better mlx_pixel_put, which tries to push the pixel to the graphical
framework directly, whereas this one stores the pixel in memory*/
void	mmlx_pixel_put(t_data *data, int x, int y, int color);

/* Pastel psychedelic colors for fractals */
int		psychedelic_color(unsigned int iter, unsigned int max_iter);

/* FRACTAL FUNCTIONS */

/* Initialize variables. If mandelbrot, then center it appropiately */
void	fractal_init(t_ins	*ins);

/* Goes through every pixel in the screen and draws the corresponding
fractal established in t_fractal */
void	fractal(t_data *img, t_fractal *f);

/* Calculates if (px, py) converted to numbers are in the mandelbrot set,
then colors the pixel if yes*/
void	draw_mandelbrot(t_data *img, t_fractal *f, double px, double py);

/* Calculates if (px, py) converted to numbers are in the julia set,
then colors the pixel if yes*/
void	draw_julia(t_data *img, t_fractal *f, double px, double py);

/* EVENT MANAGEMENT FUNCTIONS */

/* Manages key press, like, just one time thing */
int		key_hook(int keycode, t_ins *ins);

/* Manages key press, like, a long time thing */
int		key_press(int keycode, t_ins *ins);

/* Complementary function of the key_press */
int		key_release(int keycode, t_ins *ins);

/* Constantly checks hooks */
int		loop_hook(t_ins *ins);

/* Mouse zooming */
int		mouse_hook(int keycode, int x, int y, t_ins *ins);

/* Destroy window queue for the button */
int		destroy_win(t_ins *par);

#endif