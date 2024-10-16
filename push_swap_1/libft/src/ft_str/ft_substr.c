/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:19:47 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:20:20 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*loc;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) < start)
		len = 0;
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
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
