/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:29:29 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/23 18:56:39 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *d, t_mandelbrot *m)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	d->f = m;
	d->f->zoom = 1.0;
	d->f->dir_x = 0;
	d->f->dir_y = 0;
	d->f->col = 0;
	d->f->row = 0;
	d->f->x = 0;
	d->f->y = 0;
}

int		init_c(t_data *d)
{
	d->f->c_re = ((((d->f->col - (WIDTH / 2.0)) * 6.0) / WIDTH) - d->f->dir_x)
		* d->f->zoom;
	d->f->c_im = ((((d->f->row - (HEIGHT / 2.0)) * 6.0) / HEIGHT) - d->f->dir_y)
		* d->f->zoom;
	d->f->x = 0.0;
	d->f->y = 0.0;
	return (0);
}

void	draw_mandelbrot(t_data *d, int i)
{
	while (d->f->row < HEIGHT)
	{
		while (d->f->col < WIDTH)
		{
			i = init_c(d);
			while ((d->f->x * d->f->x) + (d->f->y * d->f->y) <= 4 && i < MAX)
			{
				d->f->x_new = (d->f->x * d->f->x) - (d->f->y * d->f->y)
					+ d->f->c_re;
				d->f->y = (2 * d->f->x * d->f->y) + d->f->c_im;
				d->f->x = d->f->x_new;
				i++;
			}
			if (i == MAX)
				fill_pixel(d, d->f->col, d->f->row, 0x000000);
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
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}

int		deal_mouse(int button, int x, int y, void *param)
{
	printf("button: %d - x: %d - y: %d\n", button, x, y);
	if (button == 4)
	{
		reload_image((t_data *)param);
		((t_data *)param)->f->zoom = ((t_data *)param)->f->zoom + 0.1;
		draw_mandelbrot((t_data*)param, 0);
	}
	return (0);
}

int		main(void)
{
	t_data			d;
	t_mandelbrot	m;

	ft_bzero(&d, sizeof(t_data));
	ft_bzero(&m, sizeof(t_mandelbrot));
	init_data(&d, &m);
	new_image(&d, WIDTH, HEIGHT);
	draw_mandelbrot(&d, 0);
	mlx_hook(d.win_ptr, 4, (1L << 12), &deal_mouse, (void *)&d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
