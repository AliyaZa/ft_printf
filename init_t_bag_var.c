/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_bag_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:37:47 by nhill             #+#    #+#             */
/*   Updated: 2020/12/14 17:34:09 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_t_bag_var(t_bag *bag)
{
	bag->zero = 0;
	bag->minus = 0;
	bag->period = 0;
	bag->width = 0;
	bag->precision = 0;
	bag->format_conversion = 0;
}
