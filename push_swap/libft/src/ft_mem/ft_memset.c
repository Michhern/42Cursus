/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:44:40 by michhern          #+#    #+#             */
/*   Updated: 2024/08/27 12:13:59 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
