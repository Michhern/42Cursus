/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:59:37 by michhern          #+#    #+#             */
/*   Updated: 2024/07/24 17:07:12 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p_str;
	size_t			i;

	i = 0;
	p_str = (unsigned char *)str;
	while (i < n)
	{
		if (p_str[i] == (unsigned char)c)
		{
			return ((void *)&p_str[i]);
		}
		i++;
	}
	return (NULL);
}
