/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:29:29 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/23 13:53:27 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *d, t_mandelbrot *m)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	m->zoom = 0.0;
	m->nav_x = 0.0;
	m->nav_y = 0.0;
	m->col = 0;
	m->row = 0;
}

void	draw_mandelbrot(t_data *d, t_mandelbrot *m, int x, int y)
{
	int		i;
	
	i = 0;
	printf("ahcoucuo\n");
	while (m->row < HEIGHT)
	{
		while (m->col < WIDTH)
		{
			m->c_re = ((((m->col - (WIDTH / 2.0)) * 6.0) / WIDTH) - m->nav_x)
				* m->zoom;
			m->c_im = ((((m->row - (HEIGHT / 2.0)) * 6.0) / HEIGHT) - m->nav_y)
				* m->zoom;
			x = 0;
			y = 0;
			i = 0;
			while ((x * x) + (y * y) <= 4 && i < MAX)
			{
				m->x_new = (x * x) - (y * y) + m->c_re;
				y = (2 * x * y) + m->c_im;
				x = m->x_new;
				i++;
			}
			if (i == MAX)
				fill_pixel(d, m->col, m->row, 0x000000);
			else
			{
				printf("color\n");
				m->color = (i * 255) / MAX;
				fill_pixel(d, m->col, m->row, m->color);
			}
			m->col++;
		}
		m->col = 0;
		m->row++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}

int		main(void)
{
	t_data			d;
	t_mandelbrot	m;

	ft_bzero(&d, sizeof(t_data));
	ft_bzero(&d, sizeof(t_mandelbrot));
	init_data(&d, &m);
	new_image(&d, WIDTH, HEIGHT);
	draw_mandelbrot(&d, &m, 0, 0);
	mlx_loop(d.mlx_ptr);
	return (0);
}
