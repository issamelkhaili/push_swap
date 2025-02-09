/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:05:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/09 17:01:50 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_alternating_pattern(t_stacks *stacks)
{
	int	i;
	int	alternating;

	alternating = 0;
	i = 1;
	while (i < stacks->size_a - 1)
	{
		if ((stacks->a[i - 1] > stacks->a[i] && stacks->a[i] < stacks->a[i + 1])
			|| (stacks->a[i - 1] < stacks->a[i] 
				&& stacks->a[i] > stacks->a[i + 1]))
			alternating++;
		i++;
	}
	return (alternating > stacks->size_a / 3);
}

static int	has_large_gaps(t_stacks *stacks)
{
	int	i;
	int	large_gaps;
	int	threshold;

	large_gaps = 0;
	threshold = stacks->size_a / 3;
	i = 1;
	while (i < stacks->size_a)
	{
		if (abs(stacks->a[i] - stacks->a[i - 1]) > threshold)
			large_gaps++;
		i++;
	}
	return (large_gaps > stacks->size_a / 4);
}

static int	detect_pattern_type(t_stacks *stacks)
{
	if (has_large_gaps(stacks))
		return (1);  // Large gaps pattern (like pattern 5)
	if (has_alternating_pattern(stacks))
		return (2);  // Alternating pattern
	return (0);     // Standard pattern
}

int	calculate_optimal_chunk(t_stacks *stacks)
{
	int	pattern_type;
	int	size;

	size = stacks->size_a;
	if (size <= 20)
		return (size);

	pattern_type = detect_pattern_type(stacks);
	if (size <= 100)
	{
		if (pattern_type == 1)
			return (12);      // Best for large gaps (pattern 5)
		if (pattern_type == 2)
			return (16);      // Best for alternating pattern
		return (91);         // Best for other patterns
	}
	else
	{
		if (pattern_type == 1)
			return (size / 8);
		if (pattern_type == 2)
			return (size / 6);
		return (size / 5);
	}
}
