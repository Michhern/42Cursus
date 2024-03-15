/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:04:14 by michhern          #+#    #+#             */
/*   Updated: 2024/02/04 16:45:46 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	leng;

	leng = 0;
	while (str[leng] != '\0')
		leng++;
	return (leng);
}

/*int	main(void)
{
	size_t	result = ft_strlen("firsta que tal");
	printf("%zu", result );
	return (0);
}*/
