/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:30:47 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/07 16:30:58 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define ARGS ((t_args *)arg)

void	init_ship(t_args *a)
{
	a->x1 = -2.5;
	a->y1 = -2.5 ;
	a->zoom = 200;
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

static int	color_ship(int j)
{
	int		k;
	int		colors[16];

	k = 0;
	if (j < MAX && j > 0)
	{
		k = j % 16;
		colors[0] = 0x421e0f;
		colors[1] = 0x19071a;
		colors[2] = 0x09012f;
		colors[3] = 0x040449;
		colors[4] = 0x000764;
		colors[5] = 0x0c2c8a;
		colors[6] = 0x1852b1;
		colors[7] = 0x397dd1;
		colors[8] = 0x86b5e5;
		colors[9] = 0xd3ecf8;
		colors[10] = 0xf1e9bf;
		colors[11] = 0xf8c95b;
		colors[12] = 0xffaa00;
		colors[13] = 0xcc8000;
		colors[14] = 0x995700;
		colors[15] = 0x6a3403;
	}
	return (colors[k]);
}
void		*thread_ship(void *arg)
{
	int		i;
	int		j;

	i = ARGS->start;
	while (i < ARGS->end)
	{
		j = init_c(ARGS, i);
		while ((ARGS->x * ARGS->x) + (ARGS->y * ARGS->y) <= 4 && j < MAX)
		{
			ARGS->x_new = fabs(ARGS->x * ARGS->x) - fabs(ARGS->y * ARGS->y) + ARGS->c_re;
			ARGS->y = fabs(2 * ARGS->x * ARGS->y) + ARGS->c_im;
			ARGS->x = ARGS->x_new;
			j++;
		}
		fill_pixel(&(ARGS->d), (i % W_IMG), (i / H_IMG), color_ship(j));
		i++;
	}
	return (NULL);
}

void		draw_ship(t_args *a, int i)
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
		res = pthread_create(&thr[i], NULL, thread_ship, &thr_args[i]);
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
