/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:39:39 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:35:04 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(t_bag *bag, va_list args, int *i)
{
	if (bag->format_conversion == 's')
		print_s(bag, args, i);
	else if (bag->format_conversion == 'p')
		print_p(bag, args, i);
	else if ((bag->format_conversion == 'd') || (bag->format_conversion == 'i'))
		print_d(bag, args, i);
	else if (bag->format_conversion == 'u')
		print_u(bag, args, i);
	else if (bag->format_conversion == 'x' || bag->format_conversion == 'X')
		print_x(bag, args, i);
	else if (bag->format_conversion == 'c')
		print_c(bag, args, i);
	else if (bag->format_conversion == '%')
		print_percent(bag, i);
}
