NAME	=	cube3d
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3 -w
RM		=	rm	-rf

SRCS 	= main.c	\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c \
		src/game_utils.c 					\
		src/ft_split.c						\
		src/parse.c

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re