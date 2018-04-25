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

void	draw_fractal(t_data *d)
{
	printf("name: %s\n", d->f->name);
	if (!(ft_strcmp(d->f->name, "Mandelbrot")) ||
		!(ft_strcmp(d->f->name, "mandelbrot")))
		draw_mandelbrot(d, 0);
	if (!(ft_strcmp(d->f->name, "Julia")) ||
		!(ft_strcmp(d->f->name, "julia")))
		draw_julia(d, 0);
}

void	define_direction(t_data *d, int x, int y)
{
	if (x - (WIDTH / 2) < 0)
		d->f->dir_x = d->f->dir_x - 0.1;
	if (x - (WIDTH / 2) > 0)
		d->f->dir_x = d->f->dir_x + 0.1;
	if (y - (HEIGHT / 2) < 0)
		d->f->dir_y = d->f->dir_y + 0.1;
	if (x - (HEIGHT / 2) > 0)
		d->f->dir_y = d->f->dir_y - 0.1;
	printf("dx: %f ; dy %f\n", d->f->dir_x, d->f->dir_y);
}

int		deal_key(int keycode, void *param)
{
	if (keycode == 53)
		destroy_exit((t_data *)param);
	return (0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	printf("button: %d -- x: %d ; y: %d\n", button, x, y);
	define_direction((t_data *)param, x, y);
	printf("n2: %s\n", ((t_data *)param)->f->name);
	if (button == 4 || button == 6)
	{
		reload_image((t_data *)param);
		((t_data *)param)->f->zoom = ((t_data *)param)->f->zoom + 0.1;
		draw_fractal((t_data*)param);
	}
	if (button == 5 || button == 7)
	{
		reload_image((t_data *)param);
		((t_data *)param)->f->zoom = ((t_data *)param)->f->zoom - 0.1;
		draw_fractal((t_data*)param);
	}
	return (0);
}
