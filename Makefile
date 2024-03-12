# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 09:52:02 by edfirmin          #+#    #+#              #
#    Updated: 2024/03/11 18:57:42 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = cub3d
OBJECTS  = ${SOURCES:.c=.o}

SOURCES = main.c utile1.c utile2.c get_tex.c get_tex_utile.c get_data.c get_map.c pars_map.c pars_map_utile1.c pars_map_utile2.c
MLX_PATH = ../libx
MLX      = $(MLX_PATH)/libmlx.a

CFLAGS     = -Wall -Wextra -Werror -g #-fsanitize=address
LDFLAGS    = -L ${MLX_PATH} -lm -lbsd -lX11 -lXext -lmlx

.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) lib/libft.a -o $(NAME) ../libx/libmlx.a

all: $(NAME)

$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	rm -f $(NAME)

re: fclean all