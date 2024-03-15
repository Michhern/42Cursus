/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:24:44 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 15:09:04 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

/*int	main(void)
{
	char	lower;
	char	upper;

	printf("Ingresa la letra a convertir: ");
	scanf("%c", &upper);
	lower = ft_tolower(upper);
	printf("letra convertida: %c\n", lower);
	return (0);
}*/
