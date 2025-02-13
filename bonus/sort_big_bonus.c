/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/09 17:26:23 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	calculate_chunk(int size)
{
	if (size <= 130)
		return (size / 5);
	else if (size > 130 && size <= 230)
		return (35);
	return (45);
}

static void	push_optimal_b(t_stacks *stacks, int target_idx)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (i < stacks->size_b)
	{
		if (stacks->b[i] == target_idx)
		{
			pos = i;
			break ;
		}
		i++;
	}
	if (pos <= stacks->size_b / 2)
		while (pos--)
			rb_bonus(stacks);
	else
		while (pos++ < stacks->size_b)
			rrb_bonus(stacks);
	pa_bonus(stacks);
}

static void	push_back_to_a(t_stacks *stacks)
{
	int	target;

	while (stacks->size_b > 0)
	{
		target = stacks->size_b - 1;
		push_optimal_b(stacks, target);
	}
}

static void	push_chunks_to_b(t_stacks *stacks, int chunk_size)
{
	int	curr_bonusent_size;

	while (stacks->size_a > 0)
	{
		curr_bonusent_size = stacks->size_b;
		if (stacks->a[0] < curr_bonusent_size)
		{
			pb_bonus(stacks);
			rb_bonus(stacks);
		}
		else if (stacks->a[0] < curr_bonusent_size + chunk_size)
			pb_bonus(stacks);
		else
			ra_bonus(stacks);
	}
}

void	sort_big(t_stacks *stacks)
{
	int	chunk_size;

	index_stack(stacks);
	chunk_size = calculate_chunk(stacks->size_a);
	push_chunks_to_b(stacks, chunk_size);
	push_back_to_a(stacks);
}
