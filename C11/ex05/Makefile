# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enricant <enricant@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/30 14:56:25 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = do-op.c do-op_functions.c ft_strcmp.c ft_atoi.c ft_putstr.c ft_putnbr.c
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(SRCS) doop.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Limpieza del programa
clean:
	rm -f $(NAME)

fclean: clean
