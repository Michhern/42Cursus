/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:39:19 by michhern          #+#    #+#             */
/*   Updated: 2024/02/04 16:45:46 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	char		dest[20];
	const char	*font = "firsta, mundo";
	size_t		leng = ft_strlcpy(dest, font, sizeof(dest));

	printf("Cadena copiada: %s\n", dest);
	printf("Longitud total de la cadena fuente: %zu\n", leng);
	return (0);
}*/
