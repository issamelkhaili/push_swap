/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:03:14 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/22 06:12:24 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exitandprint(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	rra(t_stacks *stacks)
{
	int	last;
	int	i;

	if (!stacks || stacks->size_a < 2)
		error_exit(stacks);
	last = stacks->a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stacks	*stacks)
{
	int	i;
	int	last;

	if (!stacks || stacks->size_b < 2)
		error_exit(stacks);
	last = stacks->b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	int	last_a;
	int	last_b;
	int	i;

	if (!stacks || stacks->size_a < 2 || stacks->size_b < 2)
		error_exit(stacks);
	last_a = stacks->a[stacks->size_a - 1];
	last_b = stacks->b[stacks->size_b - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = last_a;
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = last_b;
	write(1, "rrr\n", 4);
}
