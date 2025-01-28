/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 06:23:51 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/23 03:29:13 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
}

int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stacks	*init_stacks(int size)
{
	t_stacks	*stacks;

	if (size < 1)
		error_exit(stacks);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		error_exit(stacks);
	stacks->a = malloc(sizeof(int) * size);
	stacks->b = malloc(sizeof(int) * size);
	if (!stacks->a || !stacks->b)
		error_exit(stacks);
	return (stacks);
}
