/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 10:42:30 by micheher          #+#    #+#             */
/*   Updated: 2025/05/31 12:42:26 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*loc;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < start)
		len = 0;
	if (ft_strlen(str) - start < len)
		len = ft_srtlen(str) - start;
	loc = (char *)malloc(sizeof(char) * (len + 1));
	if (loc == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		loc[i] = str[start + i];
		i++;
	}
	loc[i] = '\0';
	return (loc);
}

/*Make substring fron the str fron position start and len symbols
there i aff.*/
/*int	main(void)
{
	const char		originalstr[] = "Hi, let's see how to check this example?";
	unsigned int	start = 4;
	size_t			leng = 13;
	char			*substring = ft_substr(originalstr, start, leng);

	if (substring != NULL)
	{
		printf ("Subcadena: %s\n", substring);
		free (substring);
	}
	else
	{
		printf ("Error al obtener la subcadena. \n");
	}
	return (0);
}*/
