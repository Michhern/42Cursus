/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:47:54 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 18:07:21 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			copy;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
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

/*int	main(void)
{
	const char	src[50] = "let's change the text";
	char		dest[50];

	strcpy(dest, "Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	return (0);
}*/
