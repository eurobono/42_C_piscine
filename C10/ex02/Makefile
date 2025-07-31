# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enricant <enricant@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/30 09:39:29 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_tail.c ft_files.c \
       ft_strcmp.c ft_memcpy.c ft_atoi.c
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(SRCS) ft_files.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Limpieza del programa
clean:
	rm -f $(NAME)

fclean: clean
