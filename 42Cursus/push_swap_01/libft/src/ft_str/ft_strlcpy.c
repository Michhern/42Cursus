/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:09:22 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:10:39 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t destsize)
{
	size_t	idx;
	size_t	leng;

	idx = 0;
	leng = 0;
	if (destsize != 0)
	{
		while (str[idx] != '\0' && idx < destsize - 1)
		{
			dest[idx] = str[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	while (str[leng] != '\0')
	{
		leng++;
	}
	return (leng);
}
