/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:45:54 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/25 16:13:46 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ARGS ((t_args * )arg)

void		init_julia(t_args *a)
{
	a->x1 = -1.3;
	a->y1 = -1.3;
	a->zoom = 300;
}

static int	init_c(t_args *a, int i)
{
	int		x;
	int		y;

	x = (i % W_IMG);
	y = (i / H_IMG);
	a->c_re = 0.285;
	a->c_im = 0.01;
	a->x = x / a->zoom + a->x1;
	a->y = y / a->zoom + a->y1;
	return (0);
}

static void	calculate_xy(t_args *a)
{
	a->x_new = (a->x * a->x) - (a->y * a->y) + a->c_re;
	a->y = (2 * a->x * a->y) + a->c_im;
	a->x = a->x_new;
}

void		*thread_julia(void *arg)
{
	int		i;
	int		j;

	i = ARGS->start;
	while (i < ARGS->end)
	{
		j = init_c(ARGS, i);
		while ((ARGS->x * ARGS->x) + (ARGS->y * ARGS->y) < 4 && j < MAX)
		{
			calculate_xy(ARGS);
			j++;
		}
		if (j == MAX)
			fill_pixel(&(ARGS->d), (i % W_IMG), (i / H_IMG), 0x0000000);
		else
		{
			ARGS->color = (j * 255) / MAX;
			fill_pixel(&(ARGS->d), (i % W_IMG), (i / H_IMG), ARGS->color);
		}
		i++;
	}
	return (NULL);
}

void		draw_julia(t_args *a, int i)
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
		thr_args[i].end = ((W_IMG * H_IMG) / NUM_THREADS) + thr_args[i].start;
		res = pthread_create(&thr[i], NULL, thread_julia, &thr_args[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		res = pthread_join(thr[i], NULL);
		i++;
	}
	mlx_put_image_to_window(a->d.mlx_ptr, a->d.win_ptr, a->d.img_ptr, X_IMG,
		Y_IMG);
}
