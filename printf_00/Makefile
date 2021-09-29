# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 21:33:31 by lfchouch          #+#    #+#              #
#    Updated: 2021/09/16 21:33:32 by lfchouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a

SRC =	ft_putchar.c	\
		ft_putstr.c		\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
                ar rc $(NAME) $(OBJ)

%.o: %.c
                $(CC) $(FLAGS) -c $< -o $@

clean :
                rm -rf $(OBJ)

bonus : $(OBJ)
                ar rc $(NAME) $(OBJ)

fclean : clean
                rm -rf $(NAME)

re : fclean all

.PHONY : fclean clean all re
