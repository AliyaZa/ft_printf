/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:40:55 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 18:11:48 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_bag *bag, int *i)
{
	int		length;
	char	c;
	int		kol;

	c = '%';
	if (bag->width < 0)
	{
		bag->width = bag->width * (-1);
		bag->minus = 1;
	}
	length = bag->width;
	kol = length;
	if (bag->minus == 0 && length > 1)
		while (--length)
			(bag->zero) ? ft_putchar('0', i) : ft_putchar(' ', i);
	ft_putchar(c, i);
	if (bag->minus == 1 && length > 1)
		while (--length > 0)
			ft_putchar(' ', i);
	while (kol--)
		i++;
}
