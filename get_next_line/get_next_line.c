/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:05:29 by michhern          #+#    #+#             */
/*   Updated: 2024/04/03 13:47:38 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	last_node = find_last_node(*list);
	if (buf == NULL || clean_node == NULL || last_node == NULL)
	{
		free(buf);
		free(clean_node);
		return ;
	}
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[j++] = last_node->str_buf[i];
	buf[j] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	free_malloc(list, clean_node, buf);
}

char	*get_a_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	str_len = len_to_newline(list);
	if (str_len <= 0)
		return (NULL);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	str_cpy(list, next_str);
	return (next_str);
}

void	lst_add_back(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		free(buf);
		return ;
	}
	new_node->str_buf = buf;
	new_node->next = NULL;
	if (last_node == NULL)
	{
		*list = new_node;
	}
	else
	{
		last_node->next = new_node;
	}
}

void	make_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		lst_add_back(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
	{
		free_malloc(&list, NULL, NULL);
		return (NULL);
	}
	make_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_a_line(list);
	if (next_line == NULL)
	{
		free_malloc(&list, NULL, NULL);
		return (NULL);
	}
	manage_list(&list);
	return (next_line);
}
