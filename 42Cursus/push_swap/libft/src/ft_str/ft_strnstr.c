/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:14:25 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:15:04 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *str, const char *finder, size_t len)
{
	size_t	position;

	position = ft_strlen((char *)finder);
	if (*finder == '\0')
	{
		return ((char *)str);
	}
	while (*str != '\0' && len >= position)
	{
		if (*str == *finder && ft_memcmp(str, finder, position) == 0)
		{
			return ((char *)str);
		}
		str++;
		len--;
	}
	return (NULL);
}
