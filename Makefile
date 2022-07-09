NAME = miniRT
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBSFLAGS = -framework OpenGl -framework AppKit
LIBS = libft.a \
	   libmlx.a
HEADERS = ./includes/

SRC = ./sources/minirt.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	$(CC) -I $(HEADERS) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	make -C ./libft/
	make -C ./minilibx
	cp ./libft/libft.a ./libft.a
	cp ./minilibx/libmlx.a ./libmlx.a
	$(CC) $(CFLAGS) $(LIBSFLAGS) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(obj)

fclean: clean
	make clean -C ./minilibx
	make fclean -C ./libft
	rm -rf $(NAME) libmlx.a

re: fclean all

.PHONY: all, clean, fclean, re
