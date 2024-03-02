# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 09:52:02 by edfirmin          #+#    #+#              #
#    Updated: 2024/03/02 12:16:29 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c utile1.c get_tex.c get_tex_utile.c get_data.c get_map.c

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o :
	gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	cd lib ; make
	gcc $(FLG) $(OBJ) minilibx-linux/libmlx_Linux.a lib/libft.a -o $(NAME)

clean :
	cd lib ; make clean
	rm -f $(OBJ)

fclean : clean
	cd lib ; make fclean
	rm -f $(NAME)

re : fclean all