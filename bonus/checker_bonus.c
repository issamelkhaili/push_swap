/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/14 13:02:43 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	execute_instruction(t_stacks *stacks, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa_bonus(stacks);
	else if (!ft_strcmp(line, "sb\n"))
		sb_bonus(stacks);
	else if (!ft_strcmp(line, "ss\n"))
		ss_bonus(stacks);
	else if (!ft_strcmp(line, "pa\n"))
		pa_bonus(stacks);
	else if (!ft_strcmp(line, "pb\n"))
		pb_bonus(stacks);
	else if (!ft_strcmp(line, "ra\n"))
		ra_bonus(stacks);
	else if (!ft_strcmp(line, "rb\n"))
		rb_bonus(stacks);
	else if (!ft_strcmp(line, "rr\n"))
		rr_bonus(stacks);
	else if (!ft_strcmp(line, "rra\n"))
		rra_bonus(stacks);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb_bonus(stacks);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr_bonus(stacks);
	else
	{
		free(line);
		error_exit(stacks);
	}
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
	char	*tmp;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			tmp = get_next_line(0);
			free(tmp);
			break ;
		}
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
