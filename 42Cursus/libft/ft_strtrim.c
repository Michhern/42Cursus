/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:50:11 by michhern          #+#    #+#             */
/*   Updated: 2024/02/06 17:22:56 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (last > first && s1[last - 1] && ft_strchr(set, s1[last - 1]))
		last--;
	if (last == 0)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (last - first + 1));
	if (str)
		ft_strlcpy(str, &s1[first], last - first + 1);
	return (str);
}*/

int	in(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
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
//Create copy of s1 by deleting set symbols from begining
//and end.
/*int	main(void)
{
	char	*test = "****test****";

	printf("%s\n", ft_strtrim(test, "*t"));
	return (0);
}*/
