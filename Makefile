CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(MINILIBX) -g
LDFLAGS = -L$(MINILIBX) -lmlx_Linux -L /usr/lib -lX11 -lXext -lbsd -lm

NAME = fractol

SRCS = src/main.c src/error_handler.c src/inits.c src/draw.c \
	   src/mandelbrot.c src/julia.c src/multibrot.c src/draw_fractal.c \
	   src/controls.c src/cleanup.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS_SRCS:.c=.o)

LIBFT = lib/libft
LIBFT_LIB = $(LIBFT)/libft.a
MINILIBX = lib/minilibx-linux
MINILIBX_LIB = $(MINILIBX)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MINILIBX_LIB) $(LDFLAGS)

$(LIBFT_LIB):
	make -C $(LIBFT)

$(MINILIBX_LIB):
	make -C $(MINILIBX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
	rm -f $(MINILIBX_LIB)
	make -C $(LIBFT) fclean
	make -C $(MINILIBX) clean

re: fclean all

.PHONY: all clean fclean re
