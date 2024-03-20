/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:32:46 by michhern          #+#    #+#             */
/*   Updated: 2024/03/07 13:44:47 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	leng;

	if (!str)
		return (-1);
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
