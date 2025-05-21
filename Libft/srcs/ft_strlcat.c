/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:17:30 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:18:49 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char		dest[20] = "firsta, ";
	const char	*font = "que tal?";
	size_t		leng = ft_strlcat(dest, font, sizeof(dest));

	printf("Cadena concatenada: %s\n", dest);
	printf("Longitud total de la cadena resultante: %zu\n", leng);
	return (0);
}*/