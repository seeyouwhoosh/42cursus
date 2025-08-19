/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/19 15:18:52 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# ifndef WIDTH
#  define WIDTH 1920
# endif // WIDTH
# ifndef HEIGHT
#  define HEIGHT 1080
# endif // HEIGHT

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
}					t_fractal;

typedef struct s_ins
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_fractal	f;
}				t_ins;

/* A better mlx_pixel_put, which tries to push the pixel to the graphical
framework directly, whereas this one stores the pixel in memory*/
void	mmlx_pixel_put(t_data *data, int x, int y, int color);

/* Fractals */

void	fractal_init(t_fractal *f);

void	mandelbrot(t_data *img, t_fractal *f);

void	draw_mandelbrot(t_data *img, t_fractal *f, double px, double py);

/* EVENT MANAGEMENT FUNCTIONS */
int		key_hook(int keycode, t_ins *ins);

void	move(int keycode, t_fractal *f);

void	zoom(int keycode, t_fractal *f);

int		mouse_hook(int keycode, int x, int y, t_ins *ins);

int		destroy_win(t_ins *par);

#endif