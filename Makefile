# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mclotild <mclotild@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 10:55:20 by mclotild          #+#    #+#              #
#   Updated: 2021/11/02 11:50:37 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES_MAC = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
#gcc  -lmlx -framework OpenGL -framework AppKit  $(SRC) libft/libft.a -o zgo
#HEADERS = -I $(INCLUDES_DIRECTORY)

LIBFT_DIRECTORY = libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a


#INCLUDES_DIRECTORY = include/
#INCLUDES_LIST = fdf.h

SRC_DIRECTORY = src/
SRC = 	src/main.c \
		   src/bresenham.c \
		   src/bresenham_utils.c \
		   src/color.c \
		   src/ft_atoi_base_m.c \
		   src/ft_substr_mod.c \
		   src/read_map.c \
		   src/read_map_utils.c \
		   src/shift_fdf.c \
		   src/utils_fdf.c \
		   src/zoom_fdf.c \

SRCS_LIBFT =        libft/libft/ft_atoi.c libft/libft/ft_bzero.c libft/libft/ft_calloc.c \
             		libft/libft/ft_isalnum.c libft/libft/ft_isalpha.c libft/libft/ft_isascii.c \
             		libft/libft/ft_isdigit.c libft/libft/ft_isprint.c libft/libft/ft_itoa.c\
             		libft/libft/ft_memccpy.c libft/libft/ft_memchr.c libft/libft/ft_memcmp.c \
             		libft/libft/ft_memcpy.c libft/libft/ft_memmove.c libft/libft/ft_memset.c \
             		libft/libft/ft_putchar_fd.c libft/libft/ft_putendl_fd.c libft/libft/ft_putnbr_fd.c \
             		libft/libft/ft_putstr_fd.c libft/libft/ft_split.c 	libft/libft/ft_strchr.c \
             		libft/libft/ft_strdup.c libft/libft/ft_strjoin.c libft/libft/ft_strlcat.c \
             		libft/libft/ft_strlcpy.c libft/libft/ft_strlen.c libft/libft/ft_strmapi.c \
             		libft/libft/ft_strncmp.c libft/libft/ft_strnstr.c libft/libft/ft_strrchr.c \
             		libft/libft/ft_strtrim.c libft/libft/ft_substr.c libft/libft/ft_tolower.c libft/libft/ft_toupper.c \
             		libft/gnl/get_next_line_utils.c libft/gnl/get_next_line.c \
             		libft/ft_printf/ft_pars_ast.c libft/ft_printf/ft_pars_wd.c libft/ft_printf/ft_pars_zero.c \
             		libft/ft_printf/ft_parsing.c libft/ft_printf/ft_print_c.c libft/ft_printf/ft_print_d.c \
             		libft/ft_printf/ft_print_p.c libft/ft_printf/ft_print_s.c libft/ft_printf/ft_print_u.c \
             		libft/ft_printf/ft_print_x.c libft/ft_printf/ft_printf.c  libft/ft_printf/ft_utils.c \
#SRC = $(addprefix $(SRC_DIRECTORY), $(SRC_FILES))
OBJS		= ${SRC:.c=.o}
OBJS_LIBFT	= ${SRCS_LIBFT:.c=.o}
HDR			= include/fdf.h
HDR_LIBFT	= libft/libft/libft.h

MINILIBX_DIRECTORY = /usr/local/lib/

all: $(NAME) $(OBJS) $(HDR) $(HDR_LIBFT)
#all: $(NAME)

$(NAME):	$(OBJS) $(OBJS_LIBFT)
#$(NAME): $(OBJS) $(LIBFT)
	make -C libft
	gcc  -lmlx -framework OpenGL -framework AppKit  $(SRC) libft/libft.a -o $(NAME)

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

%.o: %.c $(HDR) $(HDR_LIBFT) $(CHECK_HEDR)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -sC $(LIBFT_DIRECTORY)  clean

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re