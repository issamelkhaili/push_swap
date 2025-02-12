/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/02 08:38:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sort_four(t_stacks *stacks)
{
	int	smallest_pos;

	smallest_pos = find_smallest_pos(stacks);
	if (smallest_pos == 1)
		sa(stacks);
	else if (smallest_pos == 2)
	{
		ra(stacks);
		ra(stacks);
	}
	else if (smallest_pos == 3)
		rra(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}
