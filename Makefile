NAME = fractol
NAME_LIBFT = libft/libft.a
NAME_LIBMLX = minilibx-linux/libmlx_Linux.a

INCLUDES_H = -Iinc -Ilibft -Iminilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = mandatory/src/main.c mandatory/src/fractal.c mandatory/src/render.c \
	mandatory/src/listeners.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(NAME_LIBMLX) $(NAME_LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES_H) $(NAME_LIBFT) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@

$(NAME_LIBFT): 
	make -C libft

$(NAME_LIBMLX):
	@if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux; \
	fi
	@if [ ! -f "$(NAME_LIBMLX)" ]; then \
		make -C minilibx-linux; \
	fi

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	make -C libft fclean
	make -C minilibx-linux clean
	rm -rf minilibx-linux
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
