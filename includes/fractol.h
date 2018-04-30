/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:55:05 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/25 16:04:56 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <pthread.h>

# define W_WIN 1200
# define H_WIN 1200
# define W_IMG 1200
# define H_IMG 1200
# define X_IMG ((W_WIN - W_IMG) / 2)
# define Y_IMG ((H_WIN - H_IMG) / 2)

# define MAX 150

# define NUM_THREADS 6

// typedef struct		s_args
// {
// 	int				start;
// 	int				end;
// 	t_data			*d;
// }					t_args;

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
	double			x;
	double			y;
	double			zoom;
	double			dir_x;
	double			dir_y;
	double			c_re;
	double			c_im;
	double			x_new;
	int				color;
	int				start;
	int				end;
	t_data			d;
}					t_args;

void				new_image(t_data *d, int w, int h);
void				reload_image(t_data *d);
void				fill_pixel(t_data *d, int x, int y, int color);
int					deal_mouse(int button, int x, int y, void *param);
int					deal_key(int keycode, void *param);
void				draw_mandelbrot(t_args *a, int i);
void				draw_julia(t_args *a, int i);
void				ft_error(char *str);
void				destroy_exit(t_data *d);

#endif
