# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:52:12 by edfirmin          #+#    #+#              #
#    Updated: 2024/02/29 13:38:39 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memset.c ft_strlen.c ft_tolower.c ft_toupper.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_bzero.c ft_strdup.c \
ft_strchr.c ft_strrchr.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
ft_memchr.c ft_memcmp.c ft_strncmp.c ft_strnstr.c ft_calloc.c ft_memmove.c \
ft_strjoin.c ft_substr.c ft_itoa.c ft_strtrim.c ft_split.c ft_strmapi.c \
ft_striteri.c ft_putchar.c ft_free.c ft_tab_free.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

FLG = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

.c.o :
	gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : $(OBJ_BONUS) $(OBJ)
		ar rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all