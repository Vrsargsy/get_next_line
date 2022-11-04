# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrsargsy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 16:16:05 by vrsargsy          #+#    #+#              #
#    Updated: 2022/04/28 18:18:48 by vrsargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			:= gcc

NAME 		:= gnl

FLAGS 		:= -g

SOURCE 		:= $(wildcard *.c)
OBJECTS		:= $(patsubst %.c,%.o,$(SOURCE))

all:		$(NAME)

$(OBJECTS): %.o : %.c
			@$(CC) $(FLAGS) -c $(SOURCE)

$(NAME): $(OBJECTS)
			@$(CC) $(FLAGS) $(OBJECTS) -o $(NAME) -lm

clean :
			@rm -rf $(OBJECTS)

fclean : clean
			@rm -rf $(NAME)

re : fclean all
