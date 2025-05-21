/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tupper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:19:40 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:21:32 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tupper(int c)
{
	if (c > 97 && c < 122)
		return (c - 32);
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