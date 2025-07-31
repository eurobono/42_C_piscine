# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enricant <enricant@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/30 07:48:12 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_display_file.c
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(SRCS) ft_files.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Limpieza del programa
clean:
	rm -f $(NAME)

fclean: clean
