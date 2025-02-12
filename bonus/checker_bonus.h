/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 09:58:32 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BUFFER_SIZE 1

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

char		*join_arguments_bonus(int ac, char **av);
int			check_input_bonus(int ac, char **av);
int			is_valid_argument_bonus(char *str);
long		ft_atol_bonus(const char *str);
t_stacks	*parse_input_bonus(int ac, char **av);

t_stacks	*init_stacks_bonus(int size);
int			fill_stack_a_bonus(char *str, t_stacks *stacks);
int			has_duplicates_bonus(int *array, int size);
int			is_sorted_bonus(t_stacks *stacks);

void		exit_error_bonus(void);
void		clean_exit_bonus(t_stacks *stacks);
void		error_free_bonus(char *joined);
void		free_stacks_bonus(t_stacks *stacks);
void		error_exit_bonus(t_stacks *stacks);

int			execute_instruction_bonus(t_stacks *stacks, char *instruction);
char		*get_next_line_bonus(int fd);
void		check_instructions_bonus(t_stacks *stacks);
int			is_valid_instruction_bonus(char *str);

char		*ft_strchr_bonus(const char *s, int c);
char		*ft_strjoin_gnl_bonus(char *s1, char *s2);
size_t		ft_strlen_gnl_bonus(const char *s);

size_t		ft_strlen_bonus(const char *s);
char		*ft_strdup_bonus(const char *s);
char		*ft_strjoin_bonus(char *s1, char *s2);
int			ft_strcmp_bonus(const char *s1, const char *s2);
int			ft_isdigit_bonus(int c);

#endif
