/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 14:31:03 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// includes/push_swap.h
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

// Push_swap specific operations
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// Sorting functions
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);
void	sort_big(t_stacks *stacks);
int		find_smallest_pos(t_stacks *stacks);
void	index_stack(t_stacks *stacks);

#endif
