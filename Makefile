CC = gcc -Werror -Wall -Wextra
NAME = push_swap
SRCS = main.c big_sort.c do_move.c pile.c push.c rotate.c rrotate.c sort.c swap.c target_position.c utils.c verifs.c ft_split.c
OBJS = $(SRCS:c=o)
PRINT = ft_printf/libftprintf.a

all : $(NAME)

$(PRINT): 
	make -C ft_printf

$(NAME): $(OBJS) $(PRINT)
	$(CC) $(OBJS) $(PRINT) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re