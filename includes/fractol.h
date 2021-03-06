/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:55:05 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/14 17:23:44 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <pthread.h>
# include <math.h>

# define W_WIN 800
# define H_WIN 800
# define W_IMG 800
# define H_IMG 800
# define X_IMG ((W_WIN - W_IMG) / 2)
# define Y_IMG ((H_WIN - H_IMG) / 2)

# define MAX 150

# define NUM_THREADS 8

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_string;
}					t_data;

typedef struct		s_args
{
	int				index;
	char			*name;
	double			x1;
	double			x2;
	double			y2;
	double			y1;
	int				dir_x;
	int				dir_y;
	double			zoom;
	double			c_re;
	double			c_im;
	double			x;
	double			y;
	double			x_new;
	int				color;
	int				start;
	int				end;
	int				block;
	int				iter;
	t_data			d;
}					t_args;

void				new_image(t_data *d, int w, int h);
void				reload_image(t_data *d);
void				fill_pixel(t_data *d, int x, int y, int color);
int					deal_mouse(int button, int x, int y, void *param);
int					deal_key(int keycode, void *param);
int					deal_pointer(int x, int y, void *param);
void				draw_mandelbrot(t_args *a, int i);
void				init_mandelbrot(t_args *a);
void				draw_julia(t_args *a, int i);
void				init_julia(t_args *a);
void				draw_ship(t_args *a, int i);
void				init_ship(t_args *a);
void				draw_douady(t_args *a, int i);
void				init_douady(t_args *a);
void				draw_tricorn(t_args *a, int i);
void				init_tricorn(t_args *a);
void				draw_multibrot(t_args *a, int i);
void				init_multibrot(t_args *a);
int					color_fractal(int j, int max);
void				display_interface(t_data *d);
void				ft_error(char *str);
void				destroy_exit(t_data *d);
int					ft_exit(void);

#endif
