/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:34:40 by michhern          #+#    #+#             */
/*   Updated: 2023/12/12 20:33:43 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

int	ft_strlen(char *str)
{
	char	*leng;

	leng = str;
	while (*leng != '\0')
	{
		leng++;
	}
	return (leng - str);
}

/*int	main(void)
{
	char	arr[] = "Hello";

	ft_putchar(ft_strlen(arr) + '0');
	ft_putchar('\n');
	return (0);
}*/

/*int main(void)
{
	char	*mensaje = "Hola, mundo!";
	size_t	longitud = ft_strlen(mensaje);
	
	printf("La longitud de la cadena \"%s\" es: %zu\n", mensaje, longitud);
	return (0);
}*/
