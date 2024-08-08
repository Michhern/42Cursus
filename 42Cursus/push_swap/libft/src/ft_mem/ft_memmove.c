/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:33:15 by michhern          #+#    #+#             */
/*   Updated: 2024/07/24 17:43:43 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;
	size_t				c;

	p_dest = (unsigned char *)dest;
	p_dest = (unsigned char *)src;
	c = len;
	if (!p_dest && !p_src)
	{
		while (c > 0)
		{
			p_dest[c - 1] = p_src[c - 1];
			c--;
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
