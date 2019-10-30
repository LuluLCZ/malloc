ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so


CC = clang 

OPTIONS = -c 

CFLAGS = -g3

RM = rm -Rfv

SRC =	malloc.c\
		create_new_field.c\
		get_set_base_last.c\
		search_available_house.c\
		free.c\
		realloc.c\
		calloc.c\
		show_alloc_mem.c


OBJ = $(SRC:.c=.o)

DIR_SRC = sources
DIR_OBJ = objs

SRCS = $(addprefix $(DIR_SRC)/,$(SRC))
OBJS = $(addprefix $(DIR_OBJ)/,$(OBJ))

HEAD_DIR = ./libft/

all:  $(NAME)

$(NAME) : libft $(OBJS)
	$(RM) $(NAME)
	$(CC) -shared -o $@ $(OBJS) $(HEAD_DIR)/libft.a
	ln -fs $(NAME) libft_malloc.so

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) -c $(CFLAGS) -o $@ -I./includes/ -I./libft/includes $^

libft:
	make -C $(HEAD_DIR)

clean:
	$(RM) $(OBJS)
	cd $(HEAD_DIR) && $(MAKE) $@

fclean: clean
	$(RM) $(NAME)


	make -C $(HEAD_DIR) fclean

re: fclean all

.PHONY : all clean fclean re libft
