/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:04:56 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/24 19:48:13 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_mandelbrot(int button, int x, int y, void *param)
{
	printf("x: %d ; y: %d\n", x, y);
	if (x - (WIDTH / 2) < 0)
		((t_data *)param)->f->dir_x = ((t_data *)param)->f->dir_x - 0.1;
	if (x - (WIDTH / 2) > 0)
		((t_data *)param)->f->dir_x = ((t_data *)param)->f->dir_x + 0.1;
	if (y - (HEIGHT / 2) < 0)
		((t_data *)param)->f->dir_y = ((t_data *)param)->f->dir_y + 0.1;
	if (x - (HEIGHT / 2) > 0)
		((t_data *)param)->f->dir_y = ((t_data *)param)->f->dir_y - 0.1;
	printf("dx: %f ; dy %f\n", ((t_data *)param)->f->dir_x, ((t_data *)param)->f->dir_y);
	if (button == 4 || button == 6)
	{
		reload_image((t_data *)param);
		((t_data *)param)->f->zoom = ((t_data *)param)->f->zoom + 0.1;
		draw_mandelbrot((t_data*)param, 0);
	}
	if (button == 5 || button == 7)
	{
		reload_image((t_data *)param);
		((t_data *)param)->f->zoom = ((t_data *)param)->f->zoom - 0.1;
		draw_mandelbrot((t_data*)param, 0);
	}
	return (0);
}
