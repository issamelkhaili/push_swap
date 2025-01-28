/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:42:19 by isel-kha          #+#    #+#             */
/*   Updated: 2025/01/23 04:08:17 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_countword(const char *s, const char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = i;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_wordlen(char *s, char c)
{
	size_t	lenth;
	char	*wordstart;

	lenth = 0;
	while (*s == c)
		s++;
	if (!*s)
		return (0);
	wordstart = s;
	while (*wordstart && *wordstart != c)
	{
		lenth++;
		wordstart++;
	}
	return (lenth);
}

char	**ft_malfree(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

static char	**ft_splitloop(const char *s, char c, char **result, size_t *i)
{
	size_t	word_len;

	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_len = ft_wordlen((char *)s, c);
			if (word_len == 0)
				break ;
			result[*i] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (!result[*i])
				return (ft_malfree(result, *i - 1));
			ft_strlcpy(result[*i], s, word_len + 1);
			s += word_len;
			(*i)++;
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_countword(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	result = ft_splitloop(s, c, result, &i);
	if (!result)
		return (NULL);
	result[i] = NULL;
	return (result);
}
