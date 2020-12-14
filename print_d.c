/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:23:48 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:01:47 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	g_num;
static int	g_flag;

static int	ft_len(long ch, int length, t_bag *bag)
{
	while (ch != 0)
	{
		length++;
		ch = ch / 10;
	}
	if ((bag->width > length + 1) && g_num < 0 && bag->zero == 1
		&& bag->minus == 0 && bag->precision < 0 && bag->period)
		g_flag = bag->width - length - 1;
	return (length);
}

static void	disp(t_bag *bag, int length, int kol, int *i)
{
	g_num < 0 ? kol-- : 0;
	g_num < 0 && bag->zero && bag->precision < 0 ? kol-- : 0;
	if (bag->minus == 0 && bag->width > bag->precision)
		while (kol-- > 0)
		{
			if ((bag->zero == 1 && !bag->period) ||
					(bag->zero && bag->period && bag->precision < 0))
				ft_putchar('0', i);
			else
				ft_putchar(' ', i);
		}
	g_num < 0 ? ft_putchar('-', i) : 0;
	while (length--)
		ft_putchar('0', i);
	if (bag->zero && bag->width > 0 && !bag->minus && bag->precision < 0
		&& bag->period && g_num < 0 && g_flag > 0)
		while (g_flag-- != 0)
			ft_putchar('0', i);
	if (!g_num && bag->period && !bag->precision)
		bag->width ? ft_putchar(' ', i) : 0;
	else
		ft_putnbr(g_num, i);
	if (bag->minus == 1 && bag->width > bag->precision)
		while (kol-- > 0)
			ft_putchar(' ', i);
}

static void	disp_minus(t_bag *bag, int length, int kol, int *i)
{
	if (bag->zero && g_num < 0 && bag->precision <= 0 && bag->width > 0
			&& bag->minus == 0 && !bag->period)
	{
		ft_putchar('-', i);
		kol--;
		if (bag->width > bag->precision)
		{
			while (kol-- > 0)
				if (bag->zero == 1)
					ft_putchar('0', i);
				else
					ft_putchar(' ', i);
		}
		ft_putnbr(g_num, i);
	}
	else
		disp(bag, length, kol, i);
}

void		print_d(t_bag *bag, va_list args, int *i)
{
	int		length;
	int		kol;
	int		kol_space;

	g_num = va_arg(args, int);
	g_flag = 0;
	length = 0;
	g_num == 0 ? length = 1 : 0;
	length = ft_len(g_num, length, bag);
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
	disp_minus(bag, length, kol, i);
}
