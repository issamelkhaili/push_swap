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

char	*join_arguments(int ac, char **av)
{
	char	*result;
	char	*temp;
	int		i;

	result = NULL;
	i = 1;
	while (i < ac)
	{
		if (!result)
			result = ft_strdup(av[i]);
		else
		{
			temp = ft_strjoin(result, " ");
			if (!temp)
				return (NULL);
			free(result);
			result = ft_strjoin(temp, av[i]);
			free(temp);
		}
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
