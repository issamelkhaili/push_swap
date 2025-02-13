/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 14:49:23 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "common.h"
# include "get_next_line.h"

// Checker (bonus) specific operations
void    sa_bonus(t_stacks *stacks);
void    sb_bonus(t_stacks *stacks);
void    ss_bonus(t_stacks *stacks);
void    pa_bonus(t_stacks *stacks);
void    pb_bonus(t_stacks *stacks);
void    ra_bonus(t_stacks *stacks);
void    rb_bonus(t_stacks *stacks);
void    rr_bonus(t_stacks *stacks);
void    rra_bonus(t_stacks *stacks);
void    rrb_bonus(t_stacks *stacks);
void    rrr_bonus(t_stacks *stacks);

// Sorting functions
void    sort_three(t_stacks *stacks);
void    sort_four(t_stacks *stacks);
void    sort_five(t_stacks *stacks);
void    sort_big(t_stacks *stacks);
int     find_smallest_pos(t_stacks *stacks);
void    index_stack(t_stacks *stacks);

int     ft_strcmp(const char *s1, const char *s2);

#endif
