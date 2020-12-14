/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:15:54 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 16:48:02 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr1(long int n, int *i)
{
	char		c;

	if (n > 9)
		ft_putnbr(n / 10, i);
	c = n % 10 + '0';
	ft_putchar(c, i);
}

void		ft_putnbr(long int n, int *i)
{
	if (n < 0)
		n = -n;
	ft_putnbr1(n, i);
}
