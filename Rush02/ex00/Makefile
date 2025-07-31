# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hventuri <hventuri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/30 17:21:00 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c rush02_00.c rush02_01.c rush02_02.c rush02_03.c \
       rush02_translate.c rush02_translate_generic.c \
       rush02_translate_eng.c rush02_translate_frn.c \
       rush02_translate_spa.c rush02_translate_spa01.c \
       ft_atoi.c ft_putstr.c ft_strdup.c ft_memcpy.c \
       ft_strcmp.c ft_strncmp.c
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(SRCS) rush02.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Limpieza del programa
clean:
	rm -f $(NAME)

fclean: clean
