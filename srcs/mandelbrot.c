/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:38:30 by lolivet           #+#    #+#             */
/*   Updated: 2018/04/25 16:13:45 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define ARGS ((t_args *)arg)

static int	init_c(t_args *a, int i)
{
	int		x;
	int		y;

	x = (i % W_IMG);
	y = (i / H_IMG);
	a->c_re = ((((x - (W_IMG / 2.0)) * 6.0) / W_IMG) - a->dir_x)
		* a->zoom;
	a->c_im = ((((y - (H_IMG / 2.0)) * 6.0) / H_IMG) - a->dir_y)
		* a->zoom;
	a->x = 0.0;
	a->y = 0.0;
	return (0);
}

static void	calculate_xy(t_args *a)
{
	a->x_new = (a->x * a->x) - (a->y * a->y) + a->c_re;
	a->y = (2 * a->x * a->y) + a->c_im;
	a->x = a->x_new;
}

void		*thread_mandelbrot(void *arg)
{
	int		i;
	int		j;

	i = ARGS->start;
	while (i < ARGS->end)
	{
		j = init_c(ARGS, i);
		while ((ARGS->x * ARGS->x) + (ARGS->y * ARGS->y) <= 4 && j < MAX)
		{
			calculate_xy(ARGS);
			j++;
		}
		if (j == MAX)
			fill_pixel(&(ARGS->d), (i % W_IMG), (i / H_IMG), 0x000000);
		else
		{
			ARGS->color = (j * 255) / MAX;
			fill_pixel(&(ARGS)->d, (i % W_IMG), (i / H_IMG), ARGS->color);
		}
		i++;
	}
	return (NULL);
	/*
	while (((t_args *)arg)->row < ((t_args *)arg)->end / W_IMG)
	{
		while (((t_args *)arg)->col < ((t_args *)arg)->end % H_IMG)
		{
			i = init_c(((t_args *)arg));
			while ((((t_args *)arg)->x * ((t_args *)arg)->x)
					+ (((t_args *)arg)->y * ((t_args *)arg)->y) <= 4 && i < MAX)
			{
				calculate_xy(((t_args *)arg));
				i++;
			}
			if (i == MAX)
				fill_pixel(&((t_args *)arg)->d, ((t_args *)arg)->col,
					((t_args *)arg)->row, 0x000000);
			else
			{
				((t_args *)arg)->color = (i * 255) / MAX;
				fill_pixel(&((t_args *)arg)->d, ((t_args *)arg)->col,
					((t_args *)arg)->row, ((t_args *)arg)->color);
			}
			((t_args *)arg)->col++;
		}
		((t_args *)arg)->col = 0;
		((t_args *)arg)->row++;
	}
	((t_args *)arg)->row = 0;
	((t_args *)arg)->col = 0;
	*/
	return (NULL);
}

void		draw_mandelbrot(t_args *a, int i)
{
	pthread_t	threads[NUM_THREADS];
//	int			thread_args[NUM_THREADS];
	t_args		thread_args[NUM_THREADS];
	int			result_code;
	int			index;

	(void)i;
	index = 0;
	while (index < NUM_THREADS)
	{
		ft_bzero(&thread_args[index], sizeof(t_args));
//		thread_args[index] = index;
		printf("Creating thread %d\n", index);
		thread_args[index] = *a;
		thread_args[index].index = index;
		thread_args[index].start = index * ((W_IMG * H_IMG) / NUM_THREADS);
		thread_args[index].end = ((W_IMG * H_IMG) / NUM_THREADS) + thread_args[index].start;
		result_code = pthread_create(&threads[index], NULL, thread_mandelbrot, &thread_args[index]);
		index++;		
	}
	index = 0;
	while (index < NUM_THREADS)
	{
		result_code = pthread_join(threads[index], NULL);
		printf("Thread %d completed\n", index);
		index++;
	}
	mlx_put_image_to_window(a->d.mlx_ptr, a->d.win_ptr, a->d.img_ptr, X_IMG, Y_IMG);
	printf("Finish\n");
}	
