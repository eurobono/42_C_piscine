# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enricant <enricant@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/18 11:40:05 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRCS = $(addprefix $(SRC_DIR)/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regla para compilar cada .o solo si su .c o los headers cambian
%.o: %.c $(INC_DIR)/ft.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpieza de archivos .o
clean:
	rm -f $(OBJS)

# Limpieza completa, incluye el binario libft.a
fclean: clean
	rm -f $(NAME)

# Reconstrucción completa
re: fclean all

