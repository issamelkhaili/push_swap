/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:00:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/31 10:00:00 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stacks *stacks, char **split)
{
	if (split)
		free_split(split);
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

void	split_error(char **split)
{
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_free(char	*joined)
{
	if (joined)
		free(joined);
	write(2, "Error\n", 6);
	exit(1);
}

void     free_split(char **split)
{
        int     i;

        if (!split)
                return ;
        i = 0;
        while (split[i])
                free(split[i++]);
        free(split);
}
