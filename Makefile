# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:14:51 by jidrizi           #+#    #+#              #
#    Updated: 2024/07/10 17:18:38 by jidrizi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
 
CFLAGS = -Wall -Werror -Wextra

SRC = client.c server.c

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_OBJS = $(CLIENT_SRCS:%.c=bin/%.o)
SERVER_OBJS = $(SERVER_SRCS:%.c=bin/%.o)

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

LIB = -lft -Llibft/ 
HEADER = -I libft/

DEPS = minitalk.h

all: $(CLIENT_NAME) $(SERVER_NAME)

bin:
	@mkdir -p bin

bin/%.o : %.c $(DEPS) | bin
	$(CC) -c -o $@ $< $(CFLAGS) $(HEADER)

./libft/libft.a:
	@git submodule update --init ./libft
	@make -C ./libft

$(CLIENT_NAME): ./libft/libft.a $(CLIENT_OBJS)
	$(CC) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LIB) -ldl $(HEADER) $(CFLAGS)

clean:
	@rm -rf bin
	@echo "cleaned"

fclean: clean
	@rm -f $(CLIENT_NAME) $(SERVER_NAME)
	@echo "fcleaned"

re: fclean all

.PHONY: all clean fclean re