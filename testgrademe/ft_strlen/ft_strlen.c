/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:15:54 by michhern          #+#    #+#             */
/*   Updated: 2024/05/08 15:37:44 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*int main(int argc, char *argv[])
{
	char *str = argv[1];
	int length = ft_strlen(str);

    if (argc != 2) {
        printf("Uso: %s <cadena>\n", argv[0]);
        return (1);
    }
    printf("La longitud de la cadena '%s' es %d.\n", str, length);

    return (0);
}*/
