/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:00:56 by michhern          #+#    #+#             */
/*   Updated: 2024/09/23 13:16:38 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	word;

	count = 0;
	while (*s)
	{
		word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!word)
			{
				++count;
				word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		count;
	char	**array;
	int		i;

	i = 0;
	count = count_words(s, c);
	if (!count)
		return (NULL);
	array = malloc(sizeof(char *) * (size_t)(count + 1));
	if (!array)
		return (NULL);
	while (i < count)
		array[i++] = get_next_word(s, c);
	array[i] = NULL;
	return (array);
}
