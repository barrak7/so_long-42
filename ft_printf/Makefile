CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRC=ft_printf.c ft_putnbr.c ft_putstr_sp.c ft_strlen.c \
	ft_dc.c ft_putnbr_hex.c

OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar -cr $(NAME) $(OBJ)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all
