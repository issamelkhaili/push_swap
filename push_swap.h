/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:34:26 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/23 04:42:05 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		size_max;
}				t_stacks;

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
t_stacks	*init_stacks(int size);
void		free_stacks(t_stacks *stacks);
void		error_exit(t_stacks *stacks);
int			has_duplicates(int *array, int size);
char		*join_arguments(int ac, char **av);
t_stacks	*parse_numbers(char **split, int size);
char		**split_input(int ac, char **av, t_stacks *stacks);
int			count_split_size(char **split_array);
int			is_valid_integer(const char *str, int *num);
int			ft_isdigit(int c);
size_t		ft_countword(const char *s, const char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);

#endif
