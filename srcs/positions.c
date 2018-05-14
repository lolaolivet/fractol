/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:04:56 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/25 16:08:59 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define PARAMS ((t_args *)param)

/*
** if (keycode == 24 || keycode == 27)
** {
** reload_image(&(PARAMS)->d);
** PARAMS->zoom = (keycode == 24) ? PARAMS->zoom + 50 : PARAMS->zoom - 50;
** draw_fractal(PARAMS);
** }
*/

void		draw_fractal(t_args *a)
{
	if (!(ft_strcmp(a->name, "Mandelbrot"))
		|| !(ft_strcmp(a->name, "mandelbrot")))
		draw_mandelbrot(a, 0);
	if (!(ft_strcmp(a->name, "Julia"))
		|| !(ft_strcmp(a->name, "julia")))
		draw_julia(a, 0);
	if (!(ft_strcmp(a->name, "Burningship"))
		|| !(ft_strcmp(a->name, "burningship")))
		draw_ship(a, 0);
	if (!(ft_strcmp(a->name, "Douady"))
		|| !(ft_strcmp(a->name, "douady")))
		draw_douady(a, 0);
	if (!(ft_strcmp(a->name, "Tricorn"))
		|| !(ft_strcmp(a->name, "tricorn")))
		draw_tricorn(a, 0);
	if (!(ft_strcmp(a->name, "Multibrot"))
		|| !(ft_strcmp(a->name, "multibrot")))
		draw_multibrot(a, 0);
}

static void	ft_iter(int keycode, t_args *a)
{
	if (a->iter < 1000 && a->iter > 20)
	{
		reload_image(&(a)->d);
		a->iter = (keycode == 69) ? a->iter + 10 : a->iter - 10;
		draw_fractal(a);
	}
	else
		a->iter = (a->iter >= 1000) ? 999 : 21;
}

int			deal_key(int keycode, void *param)
{
	if (keycode == 53)
		destroy_exit(&(PARAMS)->d);
	if (keycode == 49)
		PARAMS->block = (PARAMS->block == 0) ? 1 : 0;
	if (keycode == 126 || keycode == 125)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->y1 = (keycode == 126) ? PARAMS->y1 + 0.1 : PARAMS->y1 - 0.1;
		draw_fractal(PARAMS);
	}
	if (keycode == 124 | keycode == 123)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->x1 = (keycode == 124) ? PARAMS->x1 - 0.1 : PARAMS->x1 + 0.1;
		draw_fractal(PARAMS);
	}
	if (keycode == 69 || keycode == 78)
		ft_iter(keycode, PARAMS);
	return (0);
}

int			deal_mouse(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (PARAMS->zoom > 50 && PARAMS->zoom < 2147483647)
		{
			reload_image(&(PARAMS)->d);
			PARAMS->zoom = (button == 5) ? PARAMS->zoom + 10 :
				PARAMS->zoom - 10;
			draw_fractal(PARAMS);
		}
		else
			PARAMS->zoom = (PARAMS->zoom >= 2147483647) ? 2147483646 : 51;
	}
	return (0);
}

int			deal_pointer(int x, int y, void *param)
{
	if (PARAMS->block == 0 && (!(ft_strcmp(PARAMS->name, "Julia"))
		|| !(ft_strcmp(PARAMS->name, "julia"))) && ((x >= 0 && x <= W_IMG)
		&& (y >= 0 && y <= H_IMG)))
	{
		reload_image(&(PARAMS->d));
		PARAMS->c_re = ((double)x - W_IMG / 2) / (W_IMG / 2);
		PARAMS->c_im = ((double)y - H_IMG / 2) / (H_IMG / 2);
		draw_julia(PARAMS, 0);
	}
	return (0);
}
