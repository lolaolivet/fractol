/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:55:05 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/24 14:37:00 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# define WIDTH 600
# define HEIGHT 600
# define MAX 50

typedef struct		s_mandelbrot
{
	int				col;
	int				row;
	double			x;
	double			y;
	double			zoom;
	double			dir_x;
	double			dir_y;
	double			c_re;
	double			c_im;
	double			x_new;
	int				color;
}					t_mandelbrot;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_string;
	t_mandelbrot	*f;
}					t_data;

void				new_image(t_data *d, int w, int h);
void				reload_image(t_data *d);
void				fill_pixel(t_data *d, int x, int y, int color);

#endif
