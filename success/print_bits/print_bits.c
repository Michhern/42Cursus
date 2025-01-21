/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:47:55 by michhern          #+#    #+#             */
/*   Updated: 2024/12/13 13:30:53 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>*/

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				i;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

/*int main(int argc, char **argv)
{
    unsigned char number;

    if (argc != 2)
    {
        write(1, "Usage: ./program <number>\n", 26);
        return (1);
    }
    int input = atoi(argv[1]); // Convertir el argumento a un entero
    if (input < 0 || input > 255)
    {
        write(1, "Error: Please enter a number between 0 and 255.\n", 48);
        return (1);
    }
    number = (unsigned char)input; // Convertir a unsigned char (rango 0-255)
    fprintf(stderr, "Bits del numero %d\n: ", number);
    print_bits(number); // Imprime los bits del número
	return (0);
}*/
