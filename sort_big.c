/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/02 08:38:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk(int size)
{
	if (size <= 130)
		return (13);
	else if (size > 130 && size <= 230)
		return (21);
	return (41);
}

void	sort_big(t_stacks *stacks)
{
	int	chunks_size;

	index_stacks(stacks);
	chunks_size = calculate_chunk(stacks->size_a);
}
