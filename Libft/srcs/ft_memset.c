/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:29 by micheher          #+#    #+#             */
/*   Updated: 2025/05/15 12:43:46 by micheher         ###   ########.fr       */
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
	return (0);
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
