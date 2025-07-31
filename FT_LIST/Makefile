# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enricant <enricant@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 11:37:51 by enricant          #+#    #+#              #
#    Updated: 2025/07/31 11:28:07 by enricant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INC_DIR = includes

SRCS = $(addprefix $(SRC_DIR)/, ft_create_elem.c ft_list_push_front.c ft_list_size.c ft_list_last.c \
       ft_list_push_back.c ft_list_push_strs.c ft_list_clear.c ft_list_at.c ft_list_reverse.c \
       ft_list_foreach.c ft_list_foreach_if.c ft_list_find.c ft_list_remove_if.c \
       ft_list_sort.c ft_list_merge.c)
OBJS = $(SRCS:.c=.o)

# Main rule
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Regla para compilar cada .o solo si su .c o los headers cambian
%.o: %.c $(INC_DIR)/ft_list.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Limpieza de archivos .o
clean:
	rm -f $(OBJS)

# Limpieza completa, incluye el binario libft.a
fclean: clean
	rm -f $(NAME)

# Reconstrucción completa
re: fclean all

