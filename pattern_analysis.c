/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_analysis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:05:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/09 16:05:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_optimal_chunk(t_stacks *stacks)
{
	if (stacks->size_a <= 20)
		return (stacks->size_a);
	return (1);
}
