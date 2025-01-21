/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:50 by michhern          #+#    #+#             */
/*   Updated: 2024/11/13 15:04:17 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while((s1[i] == s2[i]) && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

/*int	main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Uso: %s <cadena1> <cadena2>\n", argv[0]);
        return 1;
    }

    int	result = ft_strcmp(argv[1], argv[2]);

    if (result == 0)
        printf("Las cadenas '%s' y '%s' son iguales.\n", argv[1], 
			argv[2]);
    else if (result < 0)
        printf("La cadena '%s' es menor que la cadena '%s'.\n", argv[1], 
			argv[2]);
    else
        printf("La cadena '%s' es mayor que la cadena '%s'.\n", argv[1], 
			argv[2]);
    return 0;
}*/
