/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:06:50 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/29 09:58:28 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
int is_space(char *str)
{
	if(!str) return 1;
	while(*str && *str == ' ')
		str++;
	return(*str == '\0');
}
char	*join_arguments(int ac, char **av)
{
	char	*result;
	int		i;

	if(is_space(av[1]))
	{
		write(2, "Error\n", 6);
		return(NULL);;
	}
	result = ft_strdup(av[1]);
	if (!result)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		if(is_space(av[i]))
		{
			write(2, "Error\n", 6);
			return (NULL);
		}
		result = join_args_helper(result, av[i]);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
static int	check_digits(const char *str, int i, long long *result, int sign)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		if (*result > (INT_MAX / 10) || 
			(*result == (INT_MAX / 10) && 
			((sign == 1 && (str[i] - '0') > (INT_MAX % 10)) ||
			(sign == -1 && (str[i] - '0') > ((INT_MAX % 10) + 1)))))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		*result = *result * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

int	is_valid_integer(const char *str, int *num)
{
	long long	result;
	int			sign;
	int			i;

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
	if (!check_digits(str, i, &result, sign))
		return (0);
	*num = (int)(result * sign);
	return (1);
}
