# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#              #
#    Updated: 2025/02/12 11:45:17 by isel-kha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
          operations/push_operations.c \
          operations/swap_operations.c \
          operations/rotate_operations.c \
          operations/reverse_rotate_operation.c \
          parsing/check_input.c \
          parsing/libft_utils.c \
          parsing/parsing.c \
          parsing/parsing_utils.c \
          parsing/return_error.c \
          parsing/stacks_utils.c \
          sort/index_utils.c \
          sort/sort_big.c \
          sort/sort_five.c \
          sort/sort_four.c \
          sort/sort_three.c \
          sort/sorting_utils.c

OBJ = $(SRC:.c=.o)

BONUS_SRCS = bonus/checker_bonus.c \
             bonus/operations_bonus/push_operations_bonus.c \
             bonus/operations_bonus/swap_operations_bonus.c \
             bonus/operations_bonus/rotate_operations_bonus.c \
             bonus/operations_bonus/reverse_rotate_operation_bonus.c \
             bonus/parsing_bonus/check_input_bonus.c \
             bonus/parsing_bonus/libft_utils_bonus.c \
             bonus/parsing_bonus/parsing_bonus.c \
             bonus/parsing_bonus/parsing_utils_bonus.c \
             bonus/parsing_bonus/return_error_bonus.c \
             bonus/parsing_bonus/stacks_utils_bonus.c \
             bonus/sort_bonus/index_utils_bonus.c \
             bonus/sort_bonus/sort_big_bonus.c \
             bonus/sort_bonus/sort_five_bonus.c \
             bonus/sort_bonus/sort_four_bonus.c \
             bonus/sort_bonus/sort_three_bonus.c \
             bonus/sort_bonus/sorting_utils_bonus.c \
             bonus/get_next_line/get_next_line.c \
             bonus/get_next_line/get_next_line_utils.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o) $(OBJ)

PRINTF_DIR = bonus/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

INCS = -I . -I bonus/includes

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(INCS) $(BONUS_OBJS) $(PRINTF) -o $(BONUS)

clean:
	rm -f $(OBJ) $(BONUS_OBJS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

