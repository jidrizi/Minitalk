# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 16:14:51 by jidrizi           #+#    #+#              #
#    Updated: 2024/07/06 17:11:50 by jidrizi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
 
CFLAGS = -Wall -Werror -Wextra

SRC = main.c

OBJS = $(SRC:.c=.o)

NAME = minitalk

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fcleaned"

re: fclean all

.PHONY: all clean fclean re