/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:00:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/07 10:00:00 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stacks *stacks)
{
	int	i;
	int	min;

	i = 0;
	min = stacks->a[0];
	while (i < stacks->size_a)
	{
		if (stacks->a[i] < min)
			min = stacks->a[i];
		i++;
	}
	return (min);
}

static int	find_max(t_stacks *stacks)
{
	int	i;
	int	max;

	i = 0;
	max = stacks->a[0];
	while (i < stacks->size_a)
	{
		if (stacks->a[i] > max)
			max = stacks->a[i];
		i++;
	}
	return (max);
}

static void	set_index(t_stacks *stacks, int *temp, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (j < stacks->size_a)
	{
		if (temp[j] < stacks->a[i])
			count++;
		j++;
	}
	stacks->a[i] = count;
}

void	index_stack(t_stacks *stacks)
{
	int	*temp;
	int	i;
	int	min;
	int	max;

	temp = malloc(sizeof(int) * stacks->size_a);
	if (!temp)
		error_exit(stacks);
	i = -1;
	while (++i < stacks->size_a)
		temp[i] = stacks->a[i];
	min = find_min(stacks);
	max = find_max(stacks);
	i = -1;
	while (++i < stacks->size_a)
	{
		if (stacks->a[i] == min)
			stacks->a[i] = 0;
		else if (stacks->a[i] == max)
			stacks->a[i] = stacks->size_a - 1;
		else
			set_index(stacks, temp, i);
	}
	free(temp);
}
