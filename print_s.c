/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:43:44 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:14:16 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_str;

static void	disp(t_bag *bag, int x, int length, int *i)
{
	if (bag->minus != 1 && bag->width > length)
		while (x--)
		{
			if (bag->zero == 1 && !bag->period)
				ft_putchar('0', i);
			else
				ft_putchar(' ', i);
		}
	ft_putstr(g_str, length, i);
	if (bag->minus == 1 && bag->width > length)
		while (x--)
			ft_putchar(' ', i);
}

void		print_s(t_bag *bag, va_list args, int *i)
{
	int		x;
	char	*str;
	int		length;

	str = (char *)va_arg(args, void *);
	if (str == NULL)
		str = "(null)";
	g_str = str;
	if (bag->width < 0)
	{
		bag->width = bag->width * (-1);
		bag->minus = 1;
	}
	if ((bag->precision < 0 || bag->precision > ft_strlen(str)) && bag->period)
		length = ft_strlen(str);
	else
		length = bag->precision;
	if (!bag->period)
		length = ft_strlen(str);
	if (bag->width > length)
		x = bag->width - length;
	else
		x = length;
	disp(bag, x, length, i);
}
