/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 00:30:09 by isel-kha          #+#    #+#           */
/*   Updated: 2025/01/23 00:46:22 by isel-kha         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char *str)
{
	if (!str || !*str)
		return (1);
	while (*str && *str == ' ')
		str++;
	return (*str == '\0');
}

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static int	handle_error(char **split)
{
	free_split(split);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	char		**split;
	int			i;
	int			num;

	if (ac < 2 || !av[1] || is_space(av[1]))
		return (handle_error(NULL));
	i = 1;
	while (i < ac)
		if (is_space(av[i++]))
			return (handle_error(NULL));
	split = split_input(ac, av, NULL);
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		if (!is_valid_integer(split[i], &num))
			return (handle_error(split));
		i++;
	}
	stacks = parse_numbers(split, i);
	free_split(split);
	if (!stacks)
		return (1);
	free_stacks(stacks);
	return (0);
}
