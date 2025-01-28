/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:48:14 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/23 03:57:36 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_input(int ac, char **av, t_stacks *stacks)
{
	char	**split;
	char	*joined;

	if (ac == 1)
		error_exit(NULL);
	if (ac == 2)
		split = ft_split(av[1], ' ');
	else
	{
		joined = join_arguments(ac, av);
		if (!joined)
			error_exit(stacks);
		split = ft_split(joined, ' ');
		free(joined);
	}
	if (!split)
		error_exit(stacks);
	return (split);
}

static void	fill_stack(t_stacks *stacks, char **split, int size)
{
	int	i;
	int	num;

	i = 0;
	while (i < size)
	{
		if (!is_valid_integer(split[i], &num))
			error_exit(stacks);
		stacks->a[i] = num;
		i++;
	}
}

t_stacks	*parse_numbers(char **split, int size)
{
	t_stacks	*stacks;

	stacks = init_stacks(size);
	if (!stacks)
		error_exit(NULL);
	fill_stack(stacks, split, size);
	if (has_duplicates(stacks->a, size))
		error_exit(stacks);
	stacks->size_a = size;
	stacks->size_b = 0;
	return (stacks);
}
