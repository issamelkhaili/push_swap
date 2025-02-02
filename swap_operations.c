/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:26:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/22 02:34:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exitandprint(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	sa(t_stacks *stacks)
{
	int	temp;

	if (!stacks || stacks->size_a < 2)
		clean_exit(stacks);
	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (!stacks || stacks->size_b < 2)
		clean_exit(stacks);
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stacks	*stacks)
{
	int	temp;

	if (!stacks || stacks->size_b < 2 || stacks-> size_a < 2)
		clean_exit(stacks);
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
	write(1, "ss\n", 3);
}
