/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:24:26 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/14 13:24:31 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ARGS ((t_args *)arg)

void		init_multibrot(t_args *a)
{
	a->x1 = -1.6;
	a->y1 = -1.6;
	a->zoom = 250;
	a->iter = 50;
	draw_multibrot(a, 0);
}

static int	init_c(t_args *a, int i)
{
	int		x;
	int		y;

	x = (i % W_IMG);
	y = (i / H_IMG);
	a->c_re = x / a->zoom + a->x1;
	a->c_im = y / a->zoom + a->y1;
	a->x = 0.0;
	a->y = 0.0;
	return (0);
}

static void	*thread_multibrot(void *arg)
{
	int			i;
	int			j;

	i = ARGS->start;
	while (i < ARGS->end)
	{
		j = init_c(ARGS, i);
		while ((ARGS->x * ARGS->x) + (ARGS->y * ARGS->y) <= 4 && j < ARGS->iter)
		{
			ARGS->x_new = (ARGS->x * ARGS->x * ARGS->x) -
				(3 * ARGS->x * (ARGS->y * ARGS->y)) + ARGS->c_re;
			ARGS->y = (3 * (ARGS->x * ARGS->x) * ARGS->y) -
				(ARGS->y * ARGS->y * ARGS->y) + ARGS->c_im;
			ARGS->x = ARGS->x_new;
			j++;
		}
		fill_pixel(&(ARGS->d), (i % W_IMG), (i / W_IMG),
			color_fractal(j, ARGS->iter));
		i++;
	}
	return (NULL);
}

void		draw_multibrot(t_args *a, int i)
{
	pthread_t	thr[NUM_THREADS];
	t_args		thr_args[NUM_THREADS];
	int			res;

	while (i < NUM_THREADS)
	{
		ft_bzero(&thr_args[i], sizeof(t_args));
		thr_args[i] = *a;
		thr_args[i].index = i;
		thr_args[i].start = i * ((W_IMG * H_IMG) / NUM_THREADS);
		thr_args[i].end = (i + 1) * ((W_IMG * H_IMG) / NUM_THREADS);
		res = pthread_create(&(thr[i]), NULL, thread_multibrot,
			&(thr_args[i]));
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		res = pthread_join(thr[i], NULL);
		i++;
	}
	mlx_clear_window(a->d.mlx_ptr, a->d.win_ptr);
	mlx_put_image_to_window(a->d.mlx_ptr, a->d.win_ptr, a->d.img_ptr, X_IMG,
		Y_IMG);
}
