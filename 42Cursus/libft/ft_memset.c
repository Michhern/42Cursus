/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:34:15 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 15:37:49 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t leng)
{
	unsigned char	*set;
	size_t			i;

	set = (unsigned char *)ptr;
	i = 0;
	while (i < leng)
	{
		set[i] = c;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	char	str[20] = "Esto es una prueba.";

	ft_memset(str, 'H', 7);
	//ft_memset(str, 'H', sizeof(str) - 1);
	//str[sizeof(str) - 1] = '\0';
	printf("Cadena resultante: %s\n", str);
	return (0);
}*/
