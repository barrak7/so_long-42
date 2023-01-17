CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
SRC=so_long_parser.c so_long_help.c so_long.c so_long_parser_help.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJ)
	make -C libft/
	make -C ft_printf/
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit libft/libft.a ft_printf/libftprintf.a -o $(NAME)

clean:
	Make clean -C libft/
	Make clean -C ft_printf/
	rm -f $(OBJ)

fclean:clean
	Make fclean -C libft/
	Make fclean -C ft_printf/
	rm -f $(NAME)

re:fclean all
