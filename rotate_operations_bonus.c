/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 02:46:42 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 11:05:23 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rb_bonus(t_stacks *stacks)
{
	int	first;
	int	i;

	if (!stacks || stacks->size_b < 2)
		clean_exit(stacks);
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

	if (!stacks || stacks->size_a < 2)
		clean_exit(stacks);
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
	int	first_a;
	int	first_b;
	int	i;

	if (!stacks || stacks->size_a < 2 || stacks->size_b < 2)
		clean_exit(stacks);
	first_a = stacks->a[0];
	first_b = stacks->b[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->size_a - 1] = first_a;
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->size_b - 1] = first_b;
}
