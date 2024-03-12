/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:04:14 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 15:09:26 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (c - 32);
	}
	else
		return (c);
}

/*int	main(void)
{
	char	lower;
	char	upper;

	printf("Ingresa la letra a convertir: ");
	scanf("%c", &lower);
	upper = ft_toupper(lower);
	printf("letra convertida: %c\n", upper);
	return (0);
}*/
