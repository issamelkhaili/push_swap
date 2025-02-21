/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <isel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:59:20 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/21 21:05:32 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

char	*get_line(int fd)
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
