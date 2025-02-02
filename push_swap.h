/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:26:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/22 02:34:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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
int		is_valid_input(char *str);
int		is_number(char *str);
int		is_integer(char *str);
int		is_space(char c);
int		check_duplicates(int *arr, int size);
char		*join_arguments(int ac, char **av);

/* Split Functions */
char		**ft_split(char	*s, char c);
size_t		ft_countword(const char *s, const char c);
char		**ft_malfree(char **result, int i);

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
void		exit_error(t_stacks *stacks, char **split);
void		clean_exit(t_stacks *stacks);
void    	error_free(char *joined);
void		split_error(char **split);
void		free_stacks(t_stacks *stacks);
void		free_split(char **split);
int    		check_input(int ac, char **av);
int    		is_valid_argument(char *str);

/* Utility Functions */
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_isdigit(int c);

#endif
