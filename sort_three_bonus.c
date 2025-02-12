/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/02 08:38:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	sort_two(t_stacks *stacks)
{
	if (stacks->size_a == 2)
	{
		if (stacks->a[0] > stacks->a[1])
			sa_bonus(stacks);
		return (1);
	}
	return (0);
}

void	sort_three(t_stacks *stacks)
{
	if (sort_two(stacks) == 1)
		return ;
	if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2]
		&& stacks->a[0] > stacks->a[2])
	{
		sa_bonus(stacks);
		rra_bonus(stacks);
	}
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2]
		&& stacks->a[0] > stacks->a[2])
		ra_bonus(stacks);
	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2]
		&& stacks->a[0] > stacks->a[2])
		rra_bonus(stacks);
	else if (stacks->a[0] > stacks->a[1] && stacks->a[1] < stacks->a[2]
		&& stacks->a[0] < stacks->a[2])
		sa_bonus(stacks);
	else if (stacks->a[0] < stacks->a[1] && stacks->a[1] > stacks->a[2]
		&& stacks->a[0] < stacks->a[2])
	{
		sa_bonus(stacks);
		ra_bonus(stacks);
	}
}
