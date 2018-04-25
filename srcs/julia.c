/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:45:54 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/25 16:13:46 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_c(t_data *d)
{
	d->f->c_re = 0.285;
	d->f->c_im = 0.01;
	d->f->x = ((((d->f->col - (WIDTH / 2.0)) * 6.0) / WIDTH) - d->f->dir_x)
		* d->f->zoom;
	d->f->y = ((((d->f->row - (HEIGHT / 2.0)) * 6.0) / HEIGHT) - d->f->dir_y)
		* d->f->zoom;
	return (0);
}

static void	calculate_xy(t_data *d)
{
	d->f->x_new = (d->f->x * d->f->x) - (d->f->y * d->f->y) + d->f->c_re;
	d->f->y = (2 * d->f->x * d->f->y) + d->f->c_im;
	d->f->x = d->f->x_new;
}

void		draw_julia(t_data *d, int i)
{
	while (d->f->row < HEIGHT)
	{
		while (d->f->col < WIDTH)
		{
			i = init_c(d);
			while ((d->f->x * d->f->x) + (d->f->y * d->f->y) < 4 && i < MAX)
			{
				calculate_xy(d);
				i++;
			}
			if (i == MAX)
				fill_pixel(d, d->f->col, d->f->row, 0x0000000);
			else
			{
				d->f->color = (i * 255) / MAX;
				fill_pixel(d, d->f->col, d->f->row, d->f->color);
			}
			d->f->col++;
		}
		d->f->col = 0;
		d->f->row++;
	}
	d->f->row = 0;
	d->f->col = 0;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}
