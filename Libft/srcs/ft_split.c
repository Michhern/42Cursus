/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:01:32 by micheher          #+#    #+#             */
/*   Updated: 2025/05/31 12:42:26 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
		{
			free(token_v[i]);
			i++;
		}
		free(token_v);
		return (1);
	}
	return (0);
}

static int	fill(char **token_v, const char *str, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*str)
	{
		len = 0;
		while (*str == delimeter && *str)
			str++;
		while (*str != delimeter && *str)
		{
			len++;
			str++;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], str - len, len + 1);
			i++;
		}
	}
	return (0);
}

static size_t count_tokens(const char *str, char delimeter)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*str)
	{
		inside_token = 0;
		while (*str == delimeter && *str != '\0')
			str++;
		while (*str != delimeter && *str != '\0')
		{
			if (!inside_token)
			{
				tokens++;
				inside_token = 1;
			}
			str++;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (NULL == s)
		return (NULL);
	tokens = 0;
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return (NULL);
	if (fill(token_v, s, c))
		return (NULL);
	token_v[tokens] = NULL;
	return (token_v);
}

/*int	main(void)
{
	char	*str = "     Les't    meke  a test of  this  ";
	char	**v = ft_split(str, ' ');
	int		i = 0;

	while (v[i] != NULL)
	{
		printf("%s\n", v[i]);
		i++;
	}
	free(v);
	return (0);
}*/