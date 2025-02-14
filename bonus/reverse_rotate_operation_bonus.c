/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:03:14 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/14 13:32:49 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra_bonus(t_stacks *stacks)
{
	int	last;
	int	i;

	if (!stacks || !stacks->a || stacks->size_a < 2)
		return ;
	last = stacks->a[stacks->size_a - 1];
	i = stacks->size_a - 1;
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = last;
}

void	rrb_bonus(t_stacks *stacks)
{
	int	last;
	int	i;

	if (!stacks || !stacks->b || stacks->size_b < 2)
		return ;
	last = stacks->b[stacks->size_b - 1];
	i = stacks->size_b - 1;
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = last;
}

void	rrr_bonus(t_stacks *stacks)
{
	if (!stacks || !stacks->a || !stacks->b || stacks->size_a < 2
		|| stacks->size_b < 2)
		return ;
	rra_bonus(stacks);
	rrb_bonus(stacks);
}
