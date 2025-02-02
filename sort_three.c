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

#include "push_swap.h"

static void	handle_first_cases(t_stacks *stacks)
{
	if (stacks->size_a == 2)
	{
		if (stacks->a[0] > stacks->a[1])
			sa(stacks);
		return ;
	}
	if (stacks->a[0] > stacks->a[1] && stacks->a[1] > stacks->a[2])
	{
		sa(stacks);
		rra(stacks);
	}
}

void	sort_three(t_stacks *stacks)
{
	handle_first_cases(stacks);
	if (stacks->a[0] > stacks->a[1] && stacks->a[0] > stacks->a[2])
		ra(stacks);
	else if (stacks->a[1] > stacks->a[0] && stacks->a[1] > stacks->a[2])
	{
		sa(stacks);
		ra(stacks);
	}
	else if (stacks->a[0] > stacks->a[2])
		rra(stacks);
}
