# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 16:30:35 by hel-ayac          #+#    #+#              #
#    Updated: 2021/02/27 11:48:13 by hel-ayac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = cub3d.h
UTILS = ./utils/utils.a
FRM = -framework OpenGL -framework AppKit
SRCS = 	parsing.c parsing_handler.c handler.c map_parse.c rendering.c drawing.c\
	calc.c camera.c player_cont.c sprite.c sprite_parse.c add_textures.c clean.c\
	screenshot.c checkers.c ft_lstnew.c ft_lstadd_front.c cub3d.c bmp_handler.c\

OBJ = $(SRCS:.c=.o)
CUB = cub3d.a

all : $(NAME)

$(NAME) : $(CUB)
			$(CC) cub3d.c $(CUB)  -I /usr/local/include -L /usr/local/lib/ -lmlx $(FRM) -o $(NAME)

$(UTILS) :
			make -C utils/

$(CUB) : $(OBJ) $(UTILS)
			cp $(UTILS) $(CUB)
			ar rcs $(CUB) $(OBJ)

%.o : %.c
		$(CC) -c -I $(HEADER) $<

clean :
		make clean -C utils/
		rm -rf $(OBJ)

fclean : clean
		make fclean -C utils/
		rm $(CUB) $(NAME)

re : fclean all
