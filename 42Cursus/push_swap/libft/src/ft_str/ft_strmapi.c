/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:11:30 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:12:09 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	size_t			len;
	char			*c;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		c[idx] = f(idx, s[idx]);
		idx++;
	}
	c[idx] = '\0';
	return (c);
}
