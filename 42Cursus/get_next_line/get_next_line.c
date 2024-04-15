/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:05:29 by michhern          #+#    #+#             */
/*   Updated: 2024/04/09 13:34:02 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_store(char *buf)
{
	char	*store;
	ssize_t	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == 0 || buf[1] == 0)
		return (NULL);
	store = ft_substr(buf, i + 1, ft_strlen(buf) - i);
	if (!store)
		return (NULL);
	if (*store == 0)
	{
		free(store);
		store = NULL;
	}
	return (store);
}

char	*read_next_line(int fd, char *store, char *buf, int *info)
{
	char	*tmp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(store);
			return (*info = 0, NULL);
		}
		else if (bytes_read == 0)
			break ;
		buf[bytes_read] = 0;
		tmp = store;
		store = ft_strjoin(tmp, buf);
		free(tmp);
		if (!store)
			return (*info = 0, NULL);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (store);
}

char	*new_line(char *line, int *info)
{
	char	*new_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	new_line = ft_substr(line, 0, i);
	if (new_line == NULL)
		return (*info = 0, free(line), NULL);
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	char		*buf;
	int			info;

	info = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(store), free(buf), store = NULL, buf = NULL, NULL);
	if (!buf)
		return (free(store), store = NULL, NULL);
	line = read_next_line(fd, store, buf, &info);
	free(buf);
	if (!info)
		return (store = NULL, NULL);
	buf = NULL;
	if (!line)
		return (NULL);
	store = free_store(line);
	line = new_line(line, &info);
	if (!info)
		return (free(store), store = NULL, NULL);
	return (line);
}
