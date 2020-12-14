/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:18:13 by nhill             #+#    #+#             */
/*   Updated: 2020/12/13 21:46:39 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_to_hex(unsigned long num, t_bag *bag, int *i)
{
	char		c;

	if (num > 15)
		reverse_to_hex(num / 16, bag, i);
	if (num % 16 > 9)
	{
		if (bag->format_conversion == 'X')
			c = (num % 16) + 55;
		else
			c = (num % 16) + 87;
	}
	else
		c = (num % 16) + '0';
	ft_putchar(c, i);
}
