/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:46:16 by xwu               #+#    #+#             */
/*   Updated: 2025/08/15 19:16:57 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# ifndef WIDTH
#  define WIDTH 1920
# endif // WIDTH
# ifndef HEIGHT
#  define HEIGHT 1080
# endif // HEIGHT



typedef struct s_ins
{
	void	*mlx;
	void	*win;
}			t_ins;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

/* A better mlx_pixel_put, which tries to push the pixel to the graphical
framework directly, whereas this one stores the pixel in memory*/
void	mmlx_pixel_put(t_data *data, int x, int y, int color);


/* 	EVENT MANAGEMENT FUNCTIONS */
int	key_hook(int keycode, t_ins *par);

int destroy_win(t_ins *par);


#endif