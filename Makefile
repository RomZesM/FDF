# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 10:55:20 by mclotild          #+#    #+#              #
#    Updated: 2021/10/09 11:56:43 by mclotild         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES_MAC = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit

HEADERS = -I $(INCLUDES_DIRECTORY)
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = libft/

INCLUDES_DIRECTORY = include/
INCLUDES_LIST = fdf.h

SRC_DIRECTORY = src/
SRC_LIST = main.c \
		   bresenham.c \
		   bresenham_utils.c \
		   color.c \
		   ft_atoi_base_m.c \
		   ft_substr_mod.c \
		   read_map.c \
		   read_map_utils.c \
		   shift_fdf.c \
		   utils_fdf.c \
		   zoom_fdf.c \


SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_LIST))
OBJS		= ${SRC:.c=.o}

MINILIBX_DIRECTORY = /usr/local/lib/

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBRARIES_MAC) $(HEADERS)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@rm -f $(OBJS)
	@make -sC $(LIBFT_DIRECTORY)  clean

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re