# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhill <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 19:20:25 by nhill             #+#    #+#              #
#    Updated: 2020/12/12 17:51:15 by nhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_printf.c ft_percent.c in_flags.c in_format_conversions.c init_t_bag_var.c set_flags.c ft_putchar.c ft_putstr.c print_format.c ft_isdigit.c print_s.c print_c.c ft_strlen.c print_d.c ft_putnbr.c print_u.c print_x.c reverse_to_hex.c print_p.c print_percent.c

HEAD = ft_printf.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEAD)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
