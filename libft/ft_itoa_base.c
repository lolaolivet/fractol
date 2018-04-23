/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolivet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:02:00 by lolivet           #+#    #+#             */
/*   Updated: 2018/02/17 14:28:43 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		nb;
	int		len;
	char	*base_string = "0123456789ABCDEF";
	char	*res;

	nb = value;
	len = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return("0");
	if (nb < 0)
	{
		if (base == 10)
			len++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= base;
		len++;
	}
	nb = value;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (nb)
	{
		res[--len] = base_string[nb % base];
		nb /= base;
	}
	if (value < 0 && base == 10)
		res[0] = '-';
	return (res);
}
