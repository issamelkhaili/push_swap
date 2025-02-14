/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:33:34 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/09 17:27:11 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_argument(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_argument(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]) || (i > 0 && str[i - 1] != ' '))
				return (0);
			i++;
		}
		while (str[i] && ft_isdigit(str[i]))
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && !ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
	}
	return (1);
}
