ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = malloc

CC = gcc

OPTIONS = -c

CFLAGS = -g 

RM = rm -Rfv

SRC =	${DIR_SRC}/malloc.c\
		${DIR_SRC}/create_new_field.c\
		${DIR_SRC}/get_set_base_last.c\
		${DIR_SRC}/search_available_house.c\
		${DIR_SRC}/main.c\
		${DIR_SRC}/free.c\
		${DIR_SRC}/realloc.c\
		${DIR_SRC}/calloc.c\
		${DIR_SRC}/show_alloc_mem.c

OBJ = $(SRC:.c=.o)

DIR_SRC = sources


HEAD_DIR = ./libft/

all: $(NAME)

$(NAME): $(OBJ) Makefile ./includes/malloc.h
	@$(CC) $(CFLAGS) $(OPTIONS) $(SRC)
	@cd $(HEAD_DIR) && $(MAKE)
	@$(CC) $(OBJ) ./libft/libft.a -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@cd $(HEAD_DIR) && $(MAKE) $@

fclean: clean
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@make -C $(HEAD_DIR) fclean

re: fclean all

.PHONY : all clean fclean re
