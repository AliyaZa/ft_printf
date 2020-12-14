/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 16:59:39 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:41:12 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	g_num;

static int	ft_len(long ch, int length, t_bag *bag)
{
	while (ch != 0)
	{
		length++;
		ch = ch / 16;
	}
	if (bag->width < 0)
	{
		bag->width = bag->width * (-1);
		bag->minus = 1;
	}
	return (length);
}

static void	disp(t_bag *bag, int length, int kol, int *i)
{
	int		flag;

	flag = 0;
	if (length > 0)
	{
		ft_putstr("0x", 2, i);
		flag = 1;
	}
	if (bag->minus == 0 && bag->width > bag->precision)
		while (kol-- > 0)
			ft_putchar(' ', i);
	while (length--)
		ft_putchar('0', i);
	if (!g_num && bag->period && !bag->precision)
		bag->width ? ft_putchar(' ', i) : 0;
	if (flag == 0)
		ft_putstr("0x", 2, i);
	if (!(bag->period && !bag->precision))
		reverse_to_hex(g_num, bag, i);
	if (bag->minus == 1 && bag->width > bag->precision)
		while (kol-- > 0)
			ft_putchar(' ', i);
}

void		print_p(t_bag *bag, va_list args, int *i)
{
	int		length;
	int		kol;
	int		kol_space;

	g_num = va_arg(args, unsigned long);
	if (!g_num && bag->width == 2 && bag->period)
	{
		ft_putstr("0x", 2, i);
		return ;
	}
	g_num == 0 ? length = 1 :
		(length = 0);
	length = ft_len(g_num, length, bag);
	kol = bag->width;
	kol_space = length;
	g_num == 0 ? kol_space = 1 : 0;
	if (bag->precision > length)
		length = bag->precision - length;
	else
		length = 0;
	if (bag->width > length)
		kol = bag->width - length - kol_space - 2;
	else
		bag->width = 0;
	disp(bag, length, kol, i);
}
