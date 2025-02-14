/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:26:52 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/13 14:06:54 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa_bonus(t_stacks *stacks)
{
	int	temp;

	if (!stacks || !stacks->a || stacks->size_a < 2)
		return ;
	temp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = temp;
}

void	sb_bonus(t_stacks *stacks)
{
	int	temp;

	if (!stacks || !stacks->b || stacks->size_b < 2)
		return ;
	temp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = temp;
}

void	ss_bonus(t_stacks *stacks)
{
	if (!stacks || !stacks->a || !stacks->b || stacks->size_a < 2
		|| stacks->size_b < 2)
		return ;
	sa_bonus(stacks);
	sb_bonus(stacks);
}
