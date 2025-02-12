/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 13:19:18 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
}			t_stacks;

void		sa_bonus(t_stacks *stacks);
void		sb_bonus(t_stacks *stacks);
void		ss_bonus(t_stacks *stacks);
void		pa_bonus(t_stacks *stacks);
void		pb_bonus(t_stacks *stacks);
void		ra_bonus(t_stacks *stacks);
void		rb_bonus(t_stacks *stacks);
void		rr_bonus(t_stacks *stacks);
void		rra_bonus(t_stacks *stacks);
void		rrb_bonus(t_stacks *stacks);
void		rrr_bonus(t_stacks *stacks);

char		*join_arguments(int ac, char **av);
int			check_input(int ac, char **av);
int			is_valid_argument(char *str);
long		ft_atol(const char *str);
t_stacks	*parse_input(int ac, char **av);
void		check_instructions(t_stacks *stacks);
int			is_valid_instruction(char *str);
t_stacks	*init_stacks(int size);
int			fill_stack_a(char *str, t_stacks *stacks);
int			has_duplicates(int *array, int size);
int			is_sorted(t_stacks *stacks);

void		exit_error(void);
void		clean_exit(t_stacks *stacks);
void		error_free(char *joined);
void		free_stacks(t_stacks *stacks);
void		error_exit(t_stacks *stacks);

//size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);

void		sort_three(t_stacks *stacks);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		sort_big(t_stacks *stacks);
int			find_smallest_pos(t_stacks *stacks);
void		index_stack(t_stacks *stacks);

int			ft_printf(const char *format, ...);
int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_takeu(unsigned int n);
int			ft_takex(unsigned int n);
int			ft_takep(unsigned long n);

#endif
