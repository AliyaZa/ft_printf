/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:39:29 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 18:10:58 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		kol_printed;

	kol_printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ft_percent(&format, args, &kol_printed);
		else if (*format != '%')
		{
			ft_putchar(*format, &kol_printed);
			format++;
		}
	}
	va_end(args);
	return (kol_printed);
}
