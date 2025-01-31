/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:06:50 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/30 11:05:28 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char    *join_args_helper(char *result, char *av_str)
{
    char    *temp;
    char    *new_result;

    if (!result || !av_str)
        return (NULL);
    temp = ft_strjoin(result, " ");
    if (!temp)
        return (NULL);
    new_result = ft_strjoin(temp, av_str);
    free(temp);
    free(result);  // Free the old result here
    return (new_result);
}

char    *join_arguments(int ac, char **av)
{
    char    *result;
    int     i;

    if (!av[1])
        return (NULL);
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

int	is_valid_integer(const char *str, int *num)
{
	long	result;
	int		i;
	int		sign;

	if (!str || !*str)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	*num = (int)(result * sign);
	return (1);
}
