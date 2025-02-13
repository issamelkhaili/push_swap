NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

PRINTF_DIR = src/ft_printf/
GNL_DIR = src/get_next_line/
SRC_DIR = src/
COMMON_DIR = src/common/

PRINTF_SRC = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c takep.c takeu.c takex.c
GNL_SRC = get_next_line.c get_next_line_utils.c
COMMON_SRC = libft_utils.c

SRC = main.c check_input.c parsing.c parsing_utils.c stacks_utils.c \
      return_error.c swap_operations.c push_operations.c rotate_operations.c \
      reverse_rotate_operation.c sort_three.c sort_four.c sort_five.c \
      sort_big.c index_utils.c sorting_utils.c

BONUS_SRC = checker_bonus.c check_input_bonus.c parsing_bonus.c parsing_utils_bonus.c \
            stacks_utils_bonus.c return_error_bonus.c swap_operations_bonus.c \
            push_operations_bonus.c rotate_operations_bonus.c \
            reverse_rotate_operation_bonus.c sort_three_bonus.c sort_four_bonus.c \
            sort_five_bonus.c sort_big_bonus.c index_utils_bonus.c sorting_utils_bonus.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_SRC))
GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_SRC))
COMMON_SRCS = $(addprefix $(COMMON_DIR), $(COMMON_SRC))
BONUS_SRCS = $(addprefix bonus/, $(BONUS_SRC))

OBJS = $(SRCS:.c=.o) $(PRINTF_SRCS:.c=.o) $(COMMON_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o) $(GNL_SRCS:.c=.o) $(COMMON_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
