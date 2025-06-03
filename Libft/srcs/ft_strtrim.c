/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:33:24 by micheher          #+#    #+#             */
/*   Updated: 2025/05/31 12:42:26 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static in(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (in(set, s1[first]))
		first++;
	if (first >= last)
		return (ft_strdup(""));
	while (in(set, s1[last - 1]))
		last--;
	return (ft_substr(s1, first, last - first));
}

/*Create copy of s1 by deleting set symbols from begining
and end.*/
/*int	main(void)
{
	char	*test = "****test****";

	printf("%s\n", ft_strtrim(test, "*t"));
	return (0);
}*/