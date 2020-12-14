/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:33:12 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 16:50:14 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_bag *bag, va_list args, int *i)
{
	int		x;
	int		c;

	x = bag->width;
	c = (char)va_arg(args, void *);
	if (x < 0)
	{
		x = x * (-1);
		bag->minus = 1;
	}
	if (bag->minus != 1 && x > 1)
		while (--x)
			ft_putchar(' ', i);
	ft_putchar(c, i);
	if (bag->minus == 1 && x > 1)
		while (--x)
			ft_putchar(' ', i);
}
