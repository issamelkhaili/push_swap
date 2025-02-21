/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/21 08:11:36 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	free_error_exit(t_stacks *stacks, char *line)
{
	free(line);
	error_exit(stacks);
}

static char	*ft_strjoin_char(char *str, char c)
{
	char	*result;
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	result[i + 1] = '\0';
	if (str)
		free(str);
	return (result);
}

static char	*get_line(int fd)
{
	char	*line;
	char	byte;
	int		byte_read;

	if (fd < 0 || fd > 1024)
		return (NULL);
	line = NULL;
	byte_read = read(fd, &byte, 1);
	if (byte_read <= 0)
		return (NULL);
	while (byte_read > 0)
	{
		line = ft_strjoin_char(line, byte);
		if (!line)
			return (NULL);
		if (byte == '\n')
			return (line);
		byte_read = read(fd, &byte, 1);
	}
	return (line);
}

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
		free_error_exit(stacks, line);
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
		line = get_line(0);
		if (!line)
			break;
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
