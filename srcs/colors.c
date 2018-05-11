/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 01:32:21 by lolivet           #+#    #+#             */
/*   Updated: 2018/05/11 01:32:23 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_color(int j)
{
	int		colors[16];

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
	return (colors[j % 16]);
}

int		color_fractal(int j, int max)
{
	if (j < max && j > 0)
		return (init_color(j));
	else
		return (0x421e0f);
}
