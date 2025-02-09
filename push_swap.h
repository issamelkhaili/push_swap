/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:26:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/09 17:22:58 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
}			t_stacks;

char		*join_arguments(int ac, char **av);
int			check_input(int ac, char **av);
int			is_valid_argument(char *str);
long		ft_atol(const char *str);
t_stacks	*parse_input(int ac, char **av);

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

void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
int			find_smallest_pos(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		index_stack(t_stacks *stacks);
void		sort_big(t_stacks *stacks);

void		exit_error(void);
void		clean_exit(t_stacks *stacks);
void		error_free(char *joined);
void		free_stacks(t_stacks *stacks);
void		error_exit(t_stacks *stacks);
t_stacks	*init_stacks(int size);
int			fill_stack_a(char *str, t_stacks *stacks);

int			has_duplicates(int *array, int size);
int			is_sorted(t_stacks *stacks);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_isdigit(int c);

#endif
