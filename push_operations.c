/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:33:33 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/22 06:27:58 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exitandprint(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	pa(t_stacks *stacks)
{
	int		i;

	if (!stacks || stacks->size_b < 1)
		error_exit(stacks);
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = stacks->b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks-> size_b--;
	stacks-> size_a++;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	int	i;

	if (!stacks || stacks->size_a < 1)
		error_exit(stacks);
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = stacks->a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->size_a--;
	stacks->size_b++;
	write(1, "pb\n", 3);
}
