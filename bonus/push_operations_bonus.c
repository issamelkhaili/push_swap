/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:33:33 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/14 13:31:57 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa_bonus(t_stacks *stacks)
{
	int	i;

	if (!stacks || !stacks->a || !stacks->b || stacks->size_b < 1)
		return ;
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
	stacks->size_b--;
	stacks->size_a++;
}

void	pb_bonus(t_stacks *stacks)
{
	int	i;

	if (!stacks || !stacks->a || !stacks->b || stacks->size_a < 1)
		return ;
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
}
