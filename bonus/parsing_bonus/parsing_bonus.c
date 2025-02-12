/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/02 08:38:15 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_numbers(char *joined_arguments)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (joined_arguments[i])
	{
		while (joined_arguments[i] == ' ')
			i++;
		if (joined_arguments[i])
		{
			if (ft_atol(joined_arguments + i) == 2147483650)
				return (0);
			count++;
			while (joined_arguments[i] && joined_arguments[i] != ' ')
				i++;
		}
	}
	return (count);
}

static char	*parse_arguments(int ac, char **av)
{
	char	*joined_arguments;

	if (ac == 2)
		joined_arguments = ft_strdup(av[1]);
	else
		joined_arguments = join_arguments(ac, av);
	return (joined_arguments);
}

t_stacks	*parse_input(int ac, char **av)
{
	char		*joined_arguments;
	t_stacks	*stacks;
	int			count;

	if (!av || check_input(ac, av) == 0)
		exit_error();
	if (ac < 2)
		exit(1);
	joined_arguments = parse_arguments(ac, av);
	count = check_numbers(joined_arguments);
	if (count == 0)
		error_free(joined_arguments);
	stacks = init_stacks(count);
	if (!fill_stack_a(joined_arguments, stacks))
	{
		free(joined_arguments);
		error_exit(stacks);
	}
	if (has_duplicates(stacks->a, stacks->size_a))
	{
		free(joined_arguments);
		error_exit(stacks);
	}
	free(joined_arguments);
	return (stacks);
}
