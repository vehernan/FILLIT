# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vehernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 19:51:41 by vehernan          #+#    #+#              #
#    Updated: 2019/07/13 10:58:17 by vehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = includes/libft.h
SRCS = ft*.c get_next_line/get_next_line.c
OBJS = *.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRCS) -I $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "[INFO] Library [$(NAME)] created (objects remaining in directory)"

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Library [$(NAME)] removed"

re: fclean all

.PHONY: all, clean, fclean, re
