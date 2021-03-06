/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:28:48 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/14 17:24:11 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define US "<Mandelbrot | Julia | Burningship | Douady | Tricorn | Multibrot>"

t_args	detect_fractal(t_data *d, char *str)
{
	t_args	a;

	ft_bzero(&a, sizeof(t_args));
	a.name = str;
	a.d = *d;
	if (!(ft_strcmp(str, "Mandelbrot")) || !(ft_strcmp(str, "mandelbrot")))
		init_mandelbrot(&a);
	else if (!(ft_strcmp(str, "Julia")) || !(ft_strcmp(str, "julia")))
		init_julia(&a);
	else if (!(ft_strcmp(str, "Burningship")) ||
		!(ft_strcmp(str, "burningship")))
		init_ship(&a);
	else if (!(ft_strcmp(str, "Douady")) || !(ft_strcmp(str, "douady")))
		init_douady(&a);
	else if (!(ft_strcmp(str, "Tricorn")) || !(ft_strcmp(str, "tricorn")))
		init_tricorn(&a);
	else if (!(ft_strcmp(str, "Multibrot")) || !(ft_strcmp(str, "multibrot")))
		init_multibrot(&a);
	else
		ft_error("Usage: ./fractol "US);
	return (a);
}

int		main(int argc, char **argv)
{
	t_data	d;
	t_args	a;

	if (argc != 2)
		ft_error("Usage: ./fractol "US);
	ft_bzero(&d, sizeof(t_data));
	d.mlx_ptr = mlx_init();
	d.win_ptr = mlx_new_window(d.mlx_ptr, W_WIN, H_WIN, "Fract'ol");
	new_image(&d, W_IMG, H_IMG);
	a = detect_fractal(&(d), argv[1]);
	mlx_hook(a.d.win_ptr, 4, (1L << 12), &deal_mouse, (void *)&(a));
	mlx_hook(a.d.win_ptr, 6, (1L << 6), &deal_pointer, (void*)&(a));
	mlx_hook(a.d.win_ptr, 17, 0, ft_exit, 0);
	mlx_hook(a.d.win_ptr, 2, (1L << 0), &deal_key, (void *)&(a));
	mlx_loop(a.d.mlx_ptr);
	return (0);
}
