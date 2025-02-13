/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:00:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/31 10:00:00 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_exit(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

void	clean_exit(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	exit(0);
}

void	error_free(char *joined)
{
	if (joined)
		free(joined);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
}
