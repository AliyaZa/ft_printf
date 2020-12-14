/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_format_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:07:09 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:34:48 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		in_format_conversions(char c)
{
	char	*all_format;

	all_format = "cspdiuxX%";
	while (*all_format)
	{
		if (c == *all_format)
			return (1);
		all_format++;
	}
	return (0);
}
