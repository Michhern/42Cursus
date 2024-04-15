/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:34:45 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 18:08:52 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;
	size_t				c;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	c = len;
	if (!p_dest && !p_src)
		return (0);
	if (p_src < p_dest)
	{
		while (c > 0)
		{
			p_dest[c - 1] = p_src[c -1];
			c--;
		}
	}
	else
		ft_memcpy(dest, src, len);
	return (dest);
}

/*int	main(void)
{
	unsigned char	source[30] = "este es original";
	unsigned char	dest[30] = "Prueba";

	memmove(dest, source, sizeof(source));
	printf("Original: %s\n", dest);
	ft_memmove(dest, source, 3);
	printf("Depues: %s\n", dest);
	return (0);
}*/
