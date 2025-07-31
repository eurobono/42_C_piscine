# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/31 15:16:26 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c bsq_map.c bsq_map01.c bsq_land.c bsq_land01.c \
       ft_atoi.c ft_putstr.c ft_strdup.c ft_memcpy.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(SRCS) bsq.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Limpieza del programa
clean:
	rm -f $(NAME)

fclean: clean
