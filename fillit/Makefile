# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vehernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 22:43:41 by vehernan          #+#    #+#              #
#    Updated: 2019/11/18 09:46:10 by vehernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = clang
FLAGS = -Wall -Wextra -Werror -g
INCLUDES = libft/includes
SRCS = create_map.c f_read.c solve.c tetromino.c main.c
OBJS = *.o
LIB_DIR = Libft/

$(NAME):
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES) -L $(LIB_DIR) -lft
	@echo "[INFO]  Executable [$(NAME)] created (objects remaining in both directories)"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_DIR) fclean 
	@echo "[INFO] Objects removed in both directories"
	@rm -f .DS* && rm -f ._*
	@echo "[INFO] ._files removed"


fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Executable [$(NAME)] removed"

re: fclean all
