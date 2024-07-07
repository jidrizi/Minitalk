# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:14:51 by jidrizi           #+#    #+#              #
#    Updated: 2024/07/07 17:11:56 by jidrizi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
 
CFLAGS = -Wall -Werror -Wextra

SRC = client.c server.c

OBJS = $(SRC:%.c=bin/%.o)

NAME = minitalk

LIB = -lft -Llibft/ 
HEADER = -I libft/

DEPS = minitalk.h

all: $(NAME)

bin:
	@mkdir -p bin

bin/%.o : %.c $(DEPS) | bin
	$(CC) -c -o $@ $< $(CFLAGS) $(HEADER)

./libft/libft.a:
	@git submodule update --init ./libft
	@make -C ./libft

$(NAME): ./libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) -ldl $(HEADER) $(CFLAGS)

clean:
	@rm -rf bin
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fcleaned"

re: fclean all

.PHONY: all clean fclean re