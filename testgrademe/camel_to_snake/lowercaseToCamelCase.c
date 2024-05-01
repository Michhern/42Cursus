/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowercaseToCamelCase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:53:37 by michhern          #+#    #+#             */
/*   Updated: 2024/04/30 15:01:51 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	tocamelcase(char *str)
{
	int	capitalizenext;

	capitalizenext = 0;
	while (*str != '\0')
	{
		if (*str == ' ' ) // Si encontramos un espacio
			capitalizenext = 1;// Indicamos que el próximo carácter debe ser capitalizado
		else// Si no es un espacio
		{
			if (capitalizenext)
			{
				if (*str >= 'a' && *str <= 'z')
				{
					*str -= ('a' - 'A'); // o tabien se puedes repesentar ('a' - 'A')
				}
				capitalizenext = 0;// Reiniciamos la bandera para evitar que el siguiente carácter sea capitalizado
			}
		}
		str++;
	}
}

int	main()
{
	char	str[] = "convertir este string a camel case";
	printf("String original: %s\n", str);
	
	tocamelcase(str);
	printf("String en camelCase: %s\n", str);
	return (0);
}