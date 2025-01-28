/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 04:06:26 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/23 04:54:07 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	char		**split;
	int		i;
	int		num;

	split = split_input(ac, av, NULL);
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		if (!is_valid_integer(split[i], &num))
		{
			i = 0;
			while (split[i])
				free(split[i++]);
			free(split);
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	stacks = parse_numbers(split, i);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	if (stacks)
	{
		i = 0;
		while (i < stacks->size_a)
			printf("%d ", stacks->a[i++]);
		printf("\n");
		free_stacks(stacks);
	}
	return (0);
}
