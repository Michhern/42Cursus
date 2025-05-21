/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:01:30 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:38:23 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;
	size_t				c;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)p_src;
	c = len;
	if (!p_dest && !p_src)
		return (0);
	if (p_src < p_dest)
	{
		while (c > 0)
		{
			p_dest[c - 1] = p_src[c - 1];
			c--;
		}
	}
	else
		ft_memmove(dest, src, len);
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