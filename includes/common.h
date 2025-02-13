#ifndef COMMON_H
# define COMMON_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
    int     *a;
    int     *b;
    int     size_a;
    int     size_b;
}           t_stacks;

size_t      ft_strlen(const char *s);
char        *ft_strdup(const char *s);
char        *ft_strjoin(char *s1, char *s2);
int         ft_isdigit(int c);
long        ft_atol(const char *str);

t_stacks    *init_stacks(int size);
int         fill_stack_a(char *str, t_stacks *stacks);
int         has_duplicates(int *array, int size);
int         is_sorted(t_stacks *stacks);
char        *join_arguments(int ac, char **av);
int         check_input(int ac, char **av);
int         is_valid_argument(char *str);
t_stacks    *parse_input(int ac, char **av);

void        exit_error(void);
void        error_exit(t_stacks *stacks);
void        clean_exit(t_stacks *stacks);
void        error_free(char *joined);
void        free_stacks(t_stacks *stacks);

#endif
