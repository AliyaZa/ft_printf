/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:12:03 by nhill             #+#    #+#             */
/*   Updated: 2020/12/13 22:39:13 by nhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_bag
{
	int			zero;
	int			minus;
	int			period;
	int			width;
	int			precision;
	char		format_conversion;
}				t_bag;

int				ft_atoi(const char *str);
int				ft_printf(const char *format, ...);
char			**ft_length_modif(void);
void			ft_percent(const char **format, va_list args, int *i);
int				in_flags(t_bag *bag, char c);
int				in_format_conversions(char c);
int				in_length_modif(char **length, char *length_modifier);
void			init_t_bag_var(t_bag *bag);
int				set_flags(t_bag *bag, char c);
void			ft_putchar(char c, int *i);
void			ft_putstr(char *s, int length, int *i);
int				ft_strlen(const char *s);
void			print_format(t_bag *bag, va_list args, int *i);
int				ft_isdigit(int ch);
void			print_c(t_bag *bag, va_list args, int *i);
void			print_s(t_bag *bag, va_list args, int *i);
void			ft_putnbr(long int n, int *i);
void			print_d(t_bag *bag, va_list args, int *i);
void			print_u(t_bag *bag, va_list args, int *i);
void			print_x(t_bag *bag, va_list args, int *i);
void			reverse_to_hex(unsigned long num, t_bag *bag, int *i);
void			print_p(t_bag *bag, va_list args, int *i);
void			print_percent(t_bag *bag, int *i);
#endif
