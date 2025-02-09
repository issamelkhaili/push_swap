NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  operations/reverse_rotate_operation.c \
		  operations/rotate_operations.c \
		  operations/swap_operations.c \
		  operations/push_operations.c \
		  parsing/stacks_utils.c \
		  parsing/parsing_utils.c \
		  parsing/parsing.c \
		  parsing/check_input.c \
		  parsing/libft_utils.c \
		  parsing/return_error.c \
		  sort/sort_three.c \
		  sort/sort_big.c \
		  sort/sorting_utils.c \
		  sort/index_utils.c \
		  sort/sort_four.c \
		  sort/sort_five.c

OBJS	= $(SRCS:.c=.o)

INCS	= -I .

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
