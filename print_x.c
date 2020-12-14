/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:09:26 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:28:00 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static unsigned int	g_num;

static int			ft_len(unsigned int ch, int length)
{
	while (ch != 0)
	{
		length++;
		ch = ch / 16;
	}
	return (length);
}

static void			disp(t_bag *bag, int length, int kol, int *i)
{
	if (bag->minus == 0 && bag->width > bag->precision)
	{
		while (kol-- > 0)
		{
			if ((bag->zero == 1 && !bag->period) ||
					(bag->zero && bag->period && bag->precision < 0))
				ft_putchar('0', i);
			else
				ft_putchar(' ', i);
		}
	}
	while (length--)
		ft_putchar('0', i);
	if (!g_num && bag->period && !bag->precision)
		bag->width ? ft_putchar(' ', i) : 0;
	else
		reverse_to_hex(g_num, bag, i);
	if (bag->minus == 1 && bag->width > bag->precision)
		while (kol-- > 0)
			ft_putchar(' ', i);
}

void				print_x(t_bag *bag, va_list args, int *i)
{
	int		length;
	int		kol;
	int		kol_space;

	g_num = va_arg(args, unsigned int);
	length = 0;
	if (g_num == 0)
		length = 1;
	length = ft_len(g_num, length);
	kol = bag->width;
	kol_space = length;
	if (bag->width < 0)
	{
		bag->width = bag->width * (-1);
		bag->minus = 1;
	}
	if (bag->precision > length)
		length = bag->precision - length;
	else
		length = 0;
	if (bag->width > length)
		kol = bag->width - length - kol_space;
	else
		bag->width = 0;
	disp(bag, length, kol, i);
}
