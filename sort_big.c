/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/08 15:26:11 by isel-kha         ###   ########.fr       */
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

static int	find_next_in_chunk(t_stacks *stacks, int min, int max)
{
	int	i;

	i = 0;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] >= min && stacks->a[i] <= max)
			return (i);
		i++;
	}
	return (-1);
}

static void	push_to_b(t_stacks *stacks, int pos)
{
	if (pos <= stacks->size_a / 2)
	{
		while (pos > 0)
		{
			ra(stacks);
			pos--;
		}
	}
	else
	{
		while (pos < stacks->size_a)
		{
			rra(stacks);
			pos++;
		}
	}
	pb(stacks);
}

static void	push_chunks_to_b(t_stacks *stacks, int chunk_size)
{
	int	chunk;
	int	min;
	int	max;
	int	pos;
	int	total_elements;

	chunk = 0;
	total_elements = stacks->size_a;
	while (stacks->size_a > 0)
	{
		min = chunk * chunk_size;
		max = ((chunk + 1) * chunk_size) - 1;
		if (max >= total_elements)
			max = total_elements - 1;
		while ((pos = find_next_in_chunk(stacks, min, max)) != -1)
			push_to_b(stacks, pos);
		chunk++;
	}
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

void	sort_big(t_stacks *stacks)
{
	int	chunk_size;

	index_stack(stacks);
	chunk_size = calculate_chunk(stacks->size_a);
	push_chunks_to_b(stacks, chunk_size);
	push_back_to_a(stacks);
}
