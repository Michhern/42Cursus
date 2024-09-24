/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:06:30 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:09:31 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_leng;
	size_t	src_leng;
	size_t	size_leng;

	dest_leng = 0;
	src_leng = 0;
	size_leng = 0;
	while (dest[dest_leng] != '\0')
		dest_leng++;
	while (src[src_leng] != '\0')
		src_leng++;
	if (destsize <= dest_leng)
	{
		return (src_leng + destsize);
	}
	while (src[size_leng] != '\0' && (dest_leng + size_leng) < (destsize - 1))
	{
		dest[dest_leng + size_leng] = src[size_leng];
		size_leng ++;
	}
	dest[dest_leng + size_leng] = '\0';
	return (src_leng + dest_leng);
}
