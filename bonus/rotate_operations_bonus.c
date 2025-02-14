/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:46:42 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/14 13:31:31 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rb_bonus(t_stacks *stacks)
{
	int	first;
	int	i;

	if (!stacks || !stacks->b || stacks->size_b < 2)
		return ;
	first = stacks->b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = first;
}

void	ra_bonus(t_stacks *stacks)
{
	int	first;
	int	i;

	if (!stacks || !stacks->a || stacks->size_a < 2)
		return ;
	first = stacks->a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->size_a - 1] = first;
}

void	rr_bonus(t_stacks *stacks)
{
	if (!stacks || !stacks->a || !stacks->b || stacks->size_a < 2
		|| stacks->size_b < 2)
		return ;
	ra_bonus(stacks);
	rb_bonus(stacks);
}
