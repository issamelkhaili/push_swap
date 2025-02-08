/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/08 17:28:10 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk(int size)
{
	if (size <= 130)
		return (100);
	else if (size > 130 && size <= 230)
		return (35);
	return (45);
}

static void	push_optimal_b(t_stacks *stacks, int target_idx)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (i < stacks->size_b)
	{
		if (stacks->b[i] == target_idx)
		{
			pos = i;
			break ;
		}
		i++;
	}
	if (pos <= stacks->size_b / 2)
		while (pos--)
			rb(stacks);
	else
		while (pos++ < stacks->size_b)
			rrb(stacks);
	pa(stacks);
}

static void	push_back_to_a(t_stacks *stacks)
{
	int	target;

	while (stacks->size_b > 0)
	{
		target = stacks->size_b - 1;
		push_optimal_b(stacks, target);
	}
}

static void	push_chunks_to_b(t_stacks *stacks, int chunk_size)
{
	int	current_size;

	while (stacks->size_a > 0)
	{
		current_size = stacks->size_b;
		if (stacks->a[0] < current_size)
		{
			pb(stacks);
			rb(stacks);
		}
		else if (stacks->a[0] < current_size + chunk_size)
			pb(stacks);
		else
			ra(stacks);
	}
}

void	sort_big(t_stacks *stacks)
{
	int	chunk_size;

	index_stack(stacks);
	chunk_size = calculate_optimal_chunk(stacks);
	calculate_chunk(stacks->size_a);
	push_chunks_to_b(stacks, chunk_size);
	push_back_to_a(stacks);
}
