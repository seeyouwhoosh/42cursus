/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xwu <xwu@student.42urduliz.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:59:10 by xwu               #+#    #+#             */
/*   Updated: 2025/08/17 18:59:10 by xwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	gradient_test(t_data *img)
{
	for (int j = 0; j < HEIGHT; j++)
	{
		int green = 255 - (j * 30 / HEIGHT);
		int blue = 201 + (j * 44 / HEIGHT);
		int color = 186 << 16 | (green << 8) | blue;
		for (int i = 0; i < WIDTH; i++)
			mmlx_pixel_put(img, i, j, color);
	}
}

void	draw_circle(t_data *img, int radius, t_point *center)
{
	int color = 0xFF0000;
	t_point	c;
	if (!center)
	{
		c.x = WIDTH / 2;
		c.y = HEIGHT / 2;
		center = &c;
	}
	for (int j = -radius; j <= radius; j++)
	{
		for (int i = -radius; i <= radius; i++)
		{
			if (i * i + j * j <= radius * radius)
				mmlx_pixel_put(img, center->x + i, center->y + j, color);
		}
	}
}

void	cuadratic(t_data *img)
{
	t_point	p;
	for (int px = 0; px <= WIDTH; px++)
	{
		p.x = px;
		pixel_to_math(&p);
		printf("PIXEL: %d	RECTA REAL: %lf\n", p.x, p.re);
		// 3. Calcular y = x² en coordenadas matemáticas
		double real_y = p.re * p.re;

		// 4. Convertir real_y a píxel Y
		int py = (int)((real_y - (-1.0)) * HEIGHT / (4.0 - (-1.0)));

		// invertir porque la pantalla va hacia abajo
		py = HEIGHT - py - 1;

		// 5. Pintar el punto
		if (py >= 0 && py <= HEIGHT)
			mmlx_pixel_put(img, px, py, 0xFFFFFF); // blanco
	}
}

int mandelbrot(double c_real, double c_imag, int max_iter)
{
    double z_real = 0, z_imag = 0;
    int iter = 0;

    while (z_real*z_real + z_imag*z_imag <= 4.0 && iter < max_iter)
    {
        double tmp = z_real*z_real - z_imag*z_imag + c_real;
        z_imag = 2*z_real*z_imag + c_imag;
        z_real = tmp;
        iter++;
    }
    return iter;
}