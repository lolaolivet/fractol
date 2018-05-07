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

static int	init_c(t_args *a, int i)
{
	int		x;
	int		y;

	x = (i % W_IMG);
	y = (i / H_IMG);
	a->c_re = 0.285;
	a->c_im = 0.01;
	a->x = ((((x - (W_IMG / 2.0)) * 6.0) / W_IMG) - a->dir_x)
		* a->zoom;
	a->y = ((((y - (H_IMG / 2.0)) * 6.0) / H_IMG) - a->dir_y)
		* a->zoom;
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
	pthread_t	threads[NUM_THREADS];
//	int			thread_args[NUM_THREADS];
	t_args		thread_args[NUM_THREADS];
	int			result_code;
	int			index;

	(void)i;
	index = 0;
	printf("mlx_ptr_draw: %p - img_string_draw: %p\n", a->d.mlx_ptr, a->d.img_string);	
	while (index < NUM_THREADS)
	{
		ft_bzero(&thread_args[index], sizeof(t_args));
//		thread_args[index] = index;
		printf("Creating thread %d\n", index);
		thread_args[index] = *a;
		thread_args[index].index = index;
		thread_args[index].start = index * ((W_IMG * H_IMG) / NUM_THREADS);
		thread_args[index].end = ((W_IMG * H_IMG) / NUM_THREADS) + thread_args[index].start;
		result_code = pthread_create(&threads[index], NULL, thread_julia, &thread_args[index]);
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
