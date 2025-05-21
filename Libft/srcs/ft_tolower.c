/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:22:21 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:24:17 by micheher         ###   ########.fr       */
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