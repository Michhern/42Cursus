/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:17:47 by michhern          #+#    #+#             */
/*   Updated: 2024/07/24 17:31:37 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			copy;

	p_dest = (unsigned char *)dest;
	p_dest = (unsigned char *)src;
	copy = 0;
	if (p_dest == NULL && p_src == NULL)
	{
		return (NULL);
	}
	while (copy < n)
	{
		p_dest[copy] = p_src[copy];
		copy++;
	}
	return (dest);
}
