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
	if (!(ft_strcmp(a->name, "Julia"))
		|| !(ft_strcmp(a->name, "julia")))
		draw_julia(a, 0);
	if (!(ft_strcmp(a->name, "Burningship"))
		|| !(ft_strcmp(a->name, "burningship")))
		draw_ship(a, 0);
	if (!(ft_strcmp(a->name, "Douady"))
		|| !(ft_strcmp(a->name, "douady")))
		draw_douady(a, 0);
}

int		deal_key(int keycode, void *param)
{
	if (keycode == 53)
		destroy_exit(&(PARAMS)->d);
	if (keycode == 49)
	{
		if (PARAMS->block == 0)
			PARAMS->block = 1;
		else
			PARAMS->block = 0;
		printf("in - block = %d\n", PARAMS->block);		
	}
	if (keycode == 126 || keycode == 125)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->y1 = (keycode == 126) ? PARAMS->y1 - 0.1 : PARAMS->y1 + 0.1;
		draw_fractal(PARAMS);
	}
	if (keycode == 124 | keycode == 123)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->x1 = (keycode == 124) ? PARAMS->x1 - 0.1 : PARAMS->x1 + 0.1;		
		draw_fractal(PARAMS);
	}
	return (0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 6)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->zoom = PARAMS->zoom + 50;
		draw_fractal(PARAMS);
	}
	if (button == 5 || button == 7)
	{
		reload_image(&(PARAMS)->d);
		PARAMS->zoom = PARAMS->zoom - 50;
		draw_fractal(PARAMS);
	}
	return (0);
}

int		deal_pointer(int x, int y, void *param)
{
	(void)y;
	if (PARAMS->block == 0 && (!(ft_strcmp(PARAMS->name, "Julia"))
		|| !(ft_strcmp(PARAMS->name, "julia"))) && ((x >= 0 && x <= W_IMG)
		&& (y >= 0 && y <= H_IMG)))
	{
		printf("block: %d\n", PARAMS->block);		
		reload_image(&(PARAMS->d));
		PARAMS->c_re = ((double)x - W_IMG / 2) / (W_IMG / 2);
		PARAMS->c_im = ((double)y - H_IMG / 2) / (H_IMG / 2);
		draw_julia(PARAMS, 0);
	}
	return (0);
}
