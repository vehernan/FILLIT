
NAME = fillit
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/includes
SRCS = create_map.c fillit_read.c fillit_solve.c fillit_tetromino.c main.c
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