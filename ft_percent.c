/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:56:04 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 18:11:51 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parser(t_bag *bag, const char **format_pointer, va_list args)
{
	while (set_flags(bag, **format_pointer) && in_flags(bag, **format_pointer))
		(*format_pointer)++;
	while (**format_pointer == '0' || **format_pointer == '-')
		(*format_pointer)++;
	if (ft_isdigit(**format_pointer))
		bag->width = ft_atoi(*format_pointer);
	else if (**format_pointer == '*')
	{
		((bag->width) = va_arg(args, int));
		(*format_pointer)++;
	}
	while (ft_isdigit(**format_pointer))
		(*format_pointer)++;
}

void		ft_percent(const char **format, va_list args, int *i)
{
	const char	*format_pointer;
	t_bag		*bag;

	format_pointer = ++(*format);
	bag = malloc(sizeof(t_bag));
	init_t_bag_var(bag);
	parser(bag, &format_pointer, args);
	if ((*format_pointer == '.' && (bag->period = 1))
			|| (*format_pointer == '-'))
	{
		format_pointer++;
		if (ft_isdigit(*format_pointer))
			bag->precision = ft_atoi(format_pointer);
		else if ((*format_pointer == '*') && format_pointer++)
			bag->precision = va_arg(args, int);
		while (ft_isdigit(*format_pointer))
			format_pointer++;
	}
	if (in_format_conversions(*format_pointer))
		bag->format_conversion = *format_pointer++;
	print_format(bag, args, i);
	*format = format_pointer;
	free(bag);
}
