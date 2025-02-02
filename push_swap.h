/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:26:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/02 08:18:14 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

/* Parsing Functions */
char		*join_arguments(int ac, char **av);
int			check_input(int ac, char **av);
int			is_valid_argument(char *str);
long		ft_atol(const char *str);

/* Stack Operations */
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

/* Sorting Functions */
void		sort_three(t_stacks *stacks);

/* Memory Management Functions */
void		exit_error(void);
void		clean_exit(t_stacks *stacks);
void		error_free(char *joined);
void		free_stacks(t_stacks *stacks);
void		error_exit(t_stacks *stacks);
t_stacks	*init_stacks(int size);
int     	fill_stack_a(char *str, t_stacks *stacks);

/* Utility Functions */
int			has_duplicates(int *array, int size);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_isdigit(int c);

#endif
