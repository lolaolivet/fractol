/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:23:35 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/14 17:22:35 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reload_image(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	new_image(d, W_IMG, H_IMG);
}

void	destroy_exit(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img_ptr);
	exit(-1);
}

void	new_image(t_data *d, int w, int h)
{
	int		bpp;
	int		s_l;
	int		endian;

	w = W_IMG;
	h = H_IMG;
	d->img_ptr = mlx_new_image(d->mlx_ptr, w, h);
	d->img_string = mlx_get_data_addr(d->img_ptr, &(bpp), &(s_l), &(endian));
}

void	fill_pixel(t_data *d, int x, int y, int color)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;

	red = (color & 0xff0000) >> 16;
	green = (color & 0xff00) >> 8;
	blue = (color & 0xff);
	d->img_string[(y * W_IMG * 4) + (x * 4)] = blue;
	d->img_string[(y * W_IMG * 4) + (x * 4) + 1] = green;
	d->img_string[(y * W_IMG * 4) + (x * 4) + 2] = red;
}
