CC = gcc -Werror -Wall -Wextra
NAME = push_swap
SRCS = main.c big_sort.c do_move.c pile.c push.c rotate.c rrotate.c sort.c swap.c target_position.c utils.c verifs.c ft_split.c free.c
OBJS = $(SRCS:c=o)
SRCSB = do_move.c pile.c push.c rotate.c rrotate.c swap.c target_position.c verifs.c ft_split.c free.c checker.c utils.c checker_utils.c
OBJSB = $(SRCSB:c=o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFlags) $(OBJS) ft_printf/libftprintf.a -o $(NAME)

bonus: $(OBJSB)
	make -C ft_printf
	gcc $(OBJSB) ft_printf/libftprintf.a gnl/get_next_line.c gnl/get_next_line_utils.c -o checker

test:
	./push_swap 5 2 3 1 6 9 8 10 15 -20 | ./checker 5 2 3 1 6 9 8 10 15 -20

clean:
	rm -f $(NAME)
	rm -f checker

fclean: clean
	make fclean -C ft_printf
	rm -f *.o

re: fclean all

.PHONY : all clean fclean re