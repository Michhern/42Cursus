/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:17:59 by micheher          #+#    #+#             */
/*   Updated: 2025/05/15 11:34:20 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*int	main(int argc, char *argv[])
{
	int i = 0;

	if (argc != 2)
	{
		printf("Uso: %s <cadena>\n", argv[0]);
		return (1);
	}

	while (argv[1][i] != '\0')
	{
		if (ft_isalpha(argv[1][i]))
			printf("'%c' es una letra.\n", argv[1][i]);
		else
			printf("'%c' NO es una letra.\n", argv[1][i]);
		i++;
	}
	return (0);
}*/
