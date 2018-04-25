/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:28:48 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/25 16:09:00 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_data *d, t_fractal *m)
{
	d->f = m;
	d->f->zoom = 1;
	d->f->dir_x = 0;
	d->f->dir_y = 0;
	d->f->col = 0;
	d->f->row = 0;
	d->f->x = 0;
	d->f->y = 0;
}

void	detect_fractal(t_data *d, char *str)
{
	t_fractal	m;

	ft_bzero(&m, sizeof(t_fractal));
	init_fractal(d, &m);
	d->f->name = str;
	printf("n: %s\n", d->f->name);
	if (!(ft_strncmp(str, "Mandelbrot", 10)) ||
		!(ft_strncmp(str, "mandelbrot", 10)))
		draw_mandelbrot(d, 0);
	if (!(ft_strncmp(str, "Julia", 5)) || !(ft_strncmp(str, "julia", 5)))
		draw_julia(d, 0);
}

int		main(int argc, char **argv)
{
	t_data			d;

	if (argc < 2 || argc > 3)
		ft_error("Usage: ./fractol [Mandelbrot] | [Julia]");
	ft_bzero(&d, sizeof(t_data));
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, WIDTH, HEIGHT, "Fract'ol");
	new_image(&d, WIDTH, HEIGHT);
	detect_fractal(&d, argv[1]);
	mlx_hook(d.win_ptr, 4, (1L << 12), &deal_mouse, (void *)&d);
	mlx_hook(d.win_ptr, 2, (1L << 0), &deal_key, (void *)&d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
