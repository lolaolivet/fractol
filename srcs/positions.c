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

void	draw_fractal(t_args *a)
{
	if (!(ft_strcmp(a->name, "Mandelbrot"))
		|| !(ft_strcmp(a->name, "mandelbrot")))
		draw_mandelbrot(a, 0);
//	if (!(ft_strcmp(d->f.name, "Julia"))
//		|| !(ft_strcmp(d->f.name, "julia")))
//		draw_julia(d, 0);
}

void	define_direction(t_args *a, int x, int y)
{
	a->dir_x = (x - (W_IMG / 2)) / 100;
	a->dir_y = (((H_IMG / 2) - y) / 100) * -1;
	printf("x: %f; y: %f\n", a->dir_x, a->dir_y);
	/*
	if (x - (WIDTH / 2) < 0)
		d->f.dir_x = d->f.dir_x - 0.1;
	if (x - (WIDTH / 2) > 0)
		d->f.dir_x = d->f.dir_x + 0.1;
	if (y - (HEIGHT / 2) < 0)
		d->f.dir_y = d->f.dir_y + 0.1;
	if (x - (HEIGHT / 2) > 0)
		d->f.dir_y = d->f.dir_y - 0.1;
	*/
}

int		deal_key(int keycode, void *param)
{
	if (keycode == 53)
		destroy_exit(&(PARAMS)->d);
	if (keycode == 126)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->dir_y = PARAMS->dir_y - 0.1;
		draw_fractal(PARAMS);
	}
	if (keycode == 125)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->dir_y = PARAMS->dir_y + 0.1;
		draw_fractal(PARAMS);
	}	
	if (keycode == 124)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->dir_x = PARAMS->dir_x + 0.1;
		draw_fractal(PARAMS);
	}	
	if (keycode == 123)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->dir_x = PARAMS->dir_x - 0.1;
		draw_fractal(PARAMS);
	}
	return (0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
//	define_direction((t_data *)param, x, y);
	if (button == 4 || button == 6)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->zoom = PARAMS->zoom + 0.1;
		draw_fractal(PARAMS);
	}
	if (button == 5 || button == 7)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->zoom = PARAMS->zoom - 0.1;
		draw_fractal(PARAMS);
	}
	return (0);
}
