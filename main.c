/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/08 15:02:02 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	printf("\n-----------------\n");
	printf("Stack A  |  Stack B\n");
	printf("-----------------\n");
	while (i < stacks->size_a || i < stacks->size_b)
	{
		if (i < stacks->size_a)
			printf("%-7d ", stacks->a[i]);
		else
			printf("        ");
		printf("|  ");
		if (i < stacks->size_b)
			printf("%-7d", stacks->b[i]);
		printf("\n");
		i++;
	}
	printf("-----------------\n\n");
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = parse_input(ac, av);
	if (!stacks)
		exit_error();
	if (!is_sorted(stacks))
	{
		if (stacks->size_a == 2 || stacks->size_a == 3)
			sort_three(stacks);
		else if (stacks->size_a == 4)
			sort_four(stacks);
		else if (stacks->size_a == 5)
			sort_five(stacks);
		else
			sort_big(stacks);
	}
	print_stacks(stacks);
	free(stacks);
	return (0);
}
