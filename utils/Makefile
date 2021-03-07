# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 16:49:39 by hel-ayac          #+#    #+#              #
#    Updated: 2021/01/16 17:07:28 by hel-ayac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= utils.a
SRCS= get_next_line_utils.c get_next_line.c ft_putstr_fd.c ft_putchar_fd.c ft_strncmp.c\
	  ft_split.c ft_atoi.c ft_memset.c


OBJ= $(SRCS:.c=.o)

INCLUDE= utils.h

FLG= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJB)

fclean: clean
	/bin/rm -f $(NAME)

bonus: all $(OBJB)
	ar rcs $(NAME) $(OBJB)

%.o: %.c
	gcc $(FLG) -c $< -I $(INCLUDE)

re: fclean all	
