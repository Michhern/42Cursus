/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:52:41 by michhern          #+#    #+#             */
/*   Updated: 2024/02/12 13:29:25 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*zero;
	size_t			c;

	zero = (unsigned char *)s;
	c = 0;
	while (c < n)
	{
		zero[c] = 0;
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
