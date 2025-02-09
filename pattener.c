/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/09 13:39:00 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sequence_length(t_stacks *stacks, int start)
{
	int	len;
	int	i;

	len = 1;
	i = start;
	while (i + 1 < stacks->size_a && stacks->a[i] < stacks->a[i + 1])
	{
		len++;
		i++;
	}
	return (len);
}

static int	get_reverse_sequence_length(t_stacks *stacks, int start)
{
	int	len;
	int	i;

	len = 1;
	i = start;
	while (i + 1 < stacks->size_a && stacks->a[i] > stacks->a[i + 1])
	{
		len++;
		i++;
	}
	return (len);
}

static int	analyze_sequences(t_stacks *stacks)
{
	int	i;
	int	longest_inc;
	int	longest_dec;
	int	current;

	i = 0;
	longest_inc = 0;
	longest_dec = 0;
	while (i < stacks->size_a)
	{
		current = get_sequence_length(stacks, i);
		if (current > longest_inc)
			longest_inc = current;
		current = get_reverse_sequence_length(stacks, i);
		if (current > longest_dec)
			longest_dec = current;
		i++;
	}
	return (longest_dec > longest_inc ? longest_dec : longest_inc);
}

static int	count_local_inversions(t_stacks *stacks)
{
	int	inversions;
	int	i;
	int	j;
	int	window;

	inversions = 0;
	window = 15;
	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		while (j < stacks->size_a && j < i + window)
		{
			if (stacks->a[i] > stacks->a[j])
				inversions++;
			j++;
		}
		i++;
	}
	return (inversions);
}

static int	detect_pattern_type(t_stacks *stacks)
{
	int	longest_seq;
	int	local_inv;
	int	size;

	size = stacks->size_a;
	longest_seq = analyze_sequences(stacks);
	local_inv = count_local_inversions(stacks);

	if (longest_seq > size / 2)
		return (1); // Mostly sorted pattern
	if (local_inv > (size * 3))
		return (2); // Heavy local disorder
	if (local_inv < size)
		return (3); // Global disorder but local order
	return (4); // Mixed pattern
}

int	calculate_optimal_chunk(t_stacks *stacks)
{
	int	pattern_type;
	int	size;

	size = stacks->size_a;
	pattern_type = detect_pattern_type(stacks);

	if (size <= 100)
	{
		if (pattern_type == 1)
			return (size / 2); // Large chunks for mostly sorted
		if (pattern_type == 2)
			return (size / 4); // Smaller chunks for local disorder
		if (pattern_type == 3)
			return (size / 3); // Medium chunks for global disorder
		return (size / 5); // Default for mixed patterns
	}
	else
	{
		if (pattern_type == 1)
			return (size / 4);
		if (pattern_type == 2)
			return (size / 8);
		if (pattern_type == 3)
			return (size / 6);
		return (size / 7);
	}
}
