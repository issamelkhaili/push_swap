/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 03:06:50 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/12 12:56:42 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	s1_letter;
	unsigned char	s2_letter;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	s1_letter = (unsigned char)s1[i];
	s2_letter = (unsigned char)s2[i];
	return (s1_letter - s2_letter);
}
