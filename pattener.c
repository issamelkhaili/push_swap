/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/08 17:23:31 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_inversions(t_stacks *stacks)
{
	int	inversions;
	int	i;
	int	j;

	inversions = 0;
	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		while (j < stacks->size_a)
		{
			if (stacks->a[i] > stacks->a[j])
				inversions++;
			j++;
		}
		i++;
	}
	return (inversions);
}

static int	get_longest_sorted_sequence(t_stacks *stacks)
{
	int	max_seq;
	int	current_seq;
	int	i;

	max_seq = 1;
	current_seq = 1;
	i = 1;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] > stacks->a[i - 1])
			current_seq++;
		else
		{
			if (current_seq > max_seq)
				max_seq = current_seq;
			current_seq = 1;
		}
		i++;
	}
	return (max_seq > current_seq ? max_seq : current_seq);
}

static int	analyze_distribution(t_stacks *stacks)
{
	int	min;
	int	max;
	int	range;
	int	i;

	min = stacks->a[0];
	max = stacks->a[0];
	i = 1;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] < min)
			min = stacks->a[i];
		if (stacks->a[i] > max)
			max = stacks->a[i];
		i++;
	}
	range = max - min;
	return (range / stacks->size_a);
}

int	calculate_optimal_chunk(t_stacks *stacks)
{
	int	inversions;
	int	longest_seq;
	int	distribution;
	int	size;
	int	chunk_size;

	size = stacks->size_a;
	inversions = count_inversions(stacks);
	longest_seq = get_longest_sorted_sequence(stacks);
	distribution = analyze_distribution(stacks);

	// High inversions = smaller chunks might be better
	if (inversions > (size * size) / 3)
		chunk_size = size / 8;
	// Long sorted sequences = larger chunks
	else if (longest_seq > size / 3)
		chunk_size = size / 2;
	// Wide distribution = medium chunks
	else if (distribution > size / 4)
		chunk_size = size / 4;
	else
		chunk_size = size / 6;

	// Ensure minimum and maximum chunk sizes
	if (chunk_size < 10)
		chunk_size = 10;
	if (chunk_size > size)
		chunk_size = size;

	return (chunk_size);
}
