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

void	init_fractal(t_args *a)
{
	a->zoom = 1;
	a->dir_x = 0;
	a->dir_y = 0;
	a->x = 0;
	a->y = 0;
}

t_args	detect_fractal(t_data *d, char *str)
{
	t_args	a;

	ft_bzero(&a, sizeof(t_args));
	init_fractal(&a);
	a.name = str;
	a.d = *d;
	if (!(ft_strcmp(str, "Mandelbrot")) || !(ft_strcmp(str, "mandelbrot")))
		draw_mandelbrot(&a, 0);
	if (!(ft_strcmp(str, "Julia")) || !(ft_strcmp(str, "julia")))
		draw_julia(&a, 0);
	if (!(ft_strcmp(str, "Buddhabrot")) || !(ft_strcmp(str, "buddhabrot")))
		draw_julia(&a, 0);
	return (a);
}

int		main(int argc, char **argv)
{
	t_data	d;
	t_args	a;

	if (argc < 2 || argc > 3)
		ft_error("Usage: ./fractol [Mandelbrot] | [Julia]");
	ft_bzero(&d, sizeof(t_data));
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, W_WIN, H_WIN, "Fract'ol");
	new_image(&d, W_IMG, H_IMG);
	a = detect_fractal(&d, argv[1]);
	mlx_hook(a.d.win_ptr, 4, (1L << 12), &deal_mouse, (void *)&(a));
	mlx_hook(a.d.win_ptr, 2, (1L << 0), &deal_key, (void *)&(a));
	printf("mlx_ptr_main: %p - img_string_main: %p\n", a.d.mlx_ptr, a.d.img_string);			
	mlx_loop(a.d.mlx_ptr);
	return (0);
}
