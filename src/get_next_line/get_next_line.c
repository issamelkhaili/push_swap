/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:35:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/15 14:57:55 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_free(char **store)
{
	free(*store);
	*store = NULL;
	return (NULL);
}

int	ft_read_from_file(int fd, char *buffer, char **store)
{
	int		read_byte;
	char	*tmp;

	read_byte = read(fd, buffer, BUFFER_SIZE);
	if (read_byte <= 0)
		return (read_byte);
	buffer[read_byte] = '\0';
	tmp = gnl_strjoin(*store, buffer);
	if (!tmp)
		return (-1);
	gnl_free(store);
	*store = tmp;
	return (read_byte);
}

char	*ft_extract_line(char **store)
{
	char	*new_pos;
	char	*tmp;
	char	*line;

	if (!*store || !**store)
		return (NULL);
	new_pos = gnl_strchr(*store, '\n');
	if (new_pos)
	{
		line = gnl_substr(*store, 0, new_pos - *store + 1);
		if (!line)
			return (NULL);
		tmp = gnl_strdup(new_pos + 1);
		if (!tmp)
			return (gnl_free(&line));
		gnl_free(store);
		*store = tmp;
		return (line);
	}
	line = gnl_strdup(*store);
	gnl_free(store);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*store;
	char			*buffer;
	char			*line;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647
		|| read(fd, 0, 0) == -1)
		return (gnl_free(&store));
	buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (gnl_free(&store));
	while (!gnl_strchr(store, '\n'))
	{
		bytes_read = ft_read_from_file(fd, buffer, &store);
		if (bytes_read == -1)
			return (free(buffer), gnl_free(&store));
		else if (bytes_read == 0)
			break ;
	}
	free(buffer);
	line = ft_extract_line(&store);
	if (!line || !*line)
		return (gnl_free(&store));
	return (line);
}
