/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/08 15:00:10 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk(int size)
{
	if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	return (45);
}

static void	push_back_to_a(t_stacks *stacks)
{
	int	max;
	int	max_pos;
	int	i;

	while (stacks->size_b > 0)
	{
		max = stacks->b[0];
		max_pos = 0;
		i = 1;
		while (i < stacks->size_b)
		{
			if (stacks->b[i] > max)
			{
				max = stacks->b[i];
				max_pos = i;
			}
			i++;
		}
		if (max_pos <= stacks->size_b / 2)
			while (max_pos--)
				rb(stacks);
		else
			while (max_pos++ < stacks->size_b)
				rrb(stacks);
		pa(stacks);
	}
}

static void	push_chunks_to_b(t_stacks *stacks, int chunk_size)
{
	int	min;
	int	max;
	int	chunk;
	int	pushed;

	chunk = 0;
	pushed = 0;
	while (stacks->size_a > 0)
	{
		min = chunk * chunk_size;
		max = (chunk + 1) * chunk_size - 1;
		if (stacks->size_a - pushed < chunk_size)
			max = stacks->size_a - 1;
		while (pushed < (chunk + 1) * chunk_size && stacks->size_a > 0)
		{
			if (stacks->a[0] >= min && stacks->a[0] <= max)
			{
				pb(stacks);
				pushed++;
			}
			else
				ra(stacks);
		}
		if (stacks->size_a > 0)
			chunk++;
	}
}

void	sort_big(t_stacks *stacks)
{
	int	chunk_size;

	index_stack(stacks);
	chunk_size = calculate_chunk(stacks->size_a);
	push_chunks_to_b(stacks, chunk_size);
	push_back_to_a(stacks);
}
