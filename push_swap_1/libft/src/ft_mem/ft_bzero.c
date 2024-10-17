/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:50:03 by michhern          #+#    #+#             */
/*   Updated: 2024/08/08 13:37:29 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
