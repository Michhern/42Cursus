/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:44:29 by micheher          #+#    #+#             */
/*   Updated: 2025/05/15 12:49:16 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*z;
	size_t			c;

	z = (unsigned char *)s;
	c = 0;
	while (c < n)
	{
		z[c] = 0;
		c++;
	}
}

/*int	main(void)
{
	char	str[] = "lest's make a test";
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	ft_bzero(str, i);
	printf("Cadena resultante: %s\n", str);
	return (0);
}*/
