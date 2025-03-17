NAME = fractol
NAME_LIBFT = libft/libft.a
NAME_LIBMLX = minilibx-linux/libmlx.a

INCLUDES_H = -Iinc -Ilibft -Iminilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/fractal.c src/render.c \
	src/listeners.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(NAME_LIBFT) $(NAME_LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES_H) $(NAME_LIBFT) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@

$(NAME_LIBFT):
	make -C libft

$(NAME_LIBMLX):
	make -C minilibx-linux

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	make -C libft fclean
	make -C minilibx-linux clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re