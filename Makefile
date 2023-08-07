CC = gcc
CFlags = -Werror -Wall -Wextra
NAME = push_swap
SRCS = main.c big_sort.c do_move.c pile.c push.c rotate.c rrotate.c sort.c swap.c target_position.c utils.c verifs.c ft_split.c
OBJS = $(SRCS:c=o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFlags) $(OBJS) ft_printf/libftprintf.a -o $(NAME)

clean:
	rm $(NAME)

fclean: clean
	make fclean -C ft_printf
	rm *.o

re: fclean all

.PHONY : all clean fclean re