/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:06:50 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/23 03:39:03 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static char	*join_args_helper(char *result, char *av_str)
{
	char	*temp;

	temp = result;
	result = ft_strjoin(result, " ");
	if (!result)
	{
		free(temp);
		return (NULL);
	}
	temp = result;
	result = ft_strjoin(result, av_str);
	if (!result)
	{
		free(temp);
		return (NULL);
	}
	return (result);
}

char	*join_arguments(int ac, char **av)
{
	char	*result;
	int		i;

	result = ft_strdup(av[1]);
	if (!result)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		result = join_args_helper(result, av[i]);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

static int	check_digits(const char *str, int i, long *result)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

int	is_valid_integer(const char *str, int *num)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	if (!check_digits(str, i, &result))
		return (0);
	if ((sign == 1 && result > INT_MAX)
		|| (sign == -1 && result * sign < INT_MIN))
		return (0);
	*num = (int)(result * sign);
	return (1);
}
