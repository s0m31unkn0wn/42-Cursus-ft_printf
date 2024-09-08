# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armirono <armirono@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 00:12:54 by armirono          #+#    #+#              #
#    Updated: 2024/08/31 17:23:18 by armirono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c printf_utils.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

%.o : %.c 
	cc -Wall -Werror -Wextra -c $< -g

clean : 
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : all