/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 10:47:42 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	execute_instruction(t_stacks *stacks, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stacks);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stacks);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stacks);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stacks);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stacks);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stacks);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stacks);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stacks);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stacks);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stacks);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stacks);
	else
		error_exit(stacks);
}

static void	check_sort(t_stacks *stacks)
{
	if (is_sorted(stacks) && stacks->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void	process_instructions(t_stacks *stacks)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_instruction(stacks, line);
		free(line);
	}
	check_sort(stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac < 2)
		return (0);
	stacks = parse_input(ac, av);
	if (!stacks)
		exit_error();
	process_instructions(stacks);
	if (stacks)
		free_stacks(stacks);
	return (0);
}
