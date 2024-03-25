/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:16:40 by michhern          #+#    #+#             */
/*   Updated: 2024/03/20 17:15:11 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrmax(int nbr)
{
	if (nbr == -2147483648)
	{
		if (write (1, "-2147483648", 11) == -1)
			return (-1);
	}
	return (11);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		return (ft_nbrmax(n));
	}
	else if (n < 0)
	{
		if (ft_putchar('-') == -1 || ft_putnbr(n * -1) == -1)
			return (-1);
	}
	else if (n < 10)
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_putnbr(n / 10) == -1 || ft_putchar(n % 10 + '0') == -1)
			return (-1);
	}
	return (ft_putnbr_len(n));
}


// ### Función `ft_nbrmax`:

// 1. `static int ft_nbrmax(int nbr)`: Esta es una función auxiliar que se encarga
// de imprimir el número -2147483648 si se proporciona como entrada.

// 2. `if (nbr == -2147483648)`: Verifica si el número proporcionado es igual
// a -2147483648, el valor mínimo representable por un `int` en sistemas de 32 bits.

// 3. `if (write(1, "-2147483648", 11) == -1)`: Si el número es -2147483648,
// se imprime directamente en la salida estándar utilizando la función `write`.
// Retorna 11, que es la longitud de caracteres de "-2147483648".

// ### Función `ft_putnbr`:

// 1. `int ft_putnbr(int n)`: Esta es la función principal que imprime un número entero
// `n` en la salida estándar.

// 2. `if (n == -2147483648)`: Verifica si el número es igual a -2147483648. Si es así,
// llama a la función auxiliar `ft_nbrmax` para imprimir el número y luego retorna la
// longitud del número impreso.

// 3. `else if (n < 0)`: Si el número es negativo, imprime el signo negativo utilizando
// `ft_putchar('-')` y luego llama recursivamente a `ft_putnbr` con el valor
// absoluto de `n`.

// 4. `else if (n < 10)`: Si el número es un solo dígito, imprime el dígito
// utilizando `ft_putchar(n + '0')`.

// 5. `else`: Si el número tiene más de un dígito, se divide en partes y se imprime
// recursivamente. La parte entera se imprime llamando a `ft_putnbr(n / 10)` y el
// último dígito se imprime llamando a `ft_putchar(n % 10 + '0')`.

// 6. `return (ft_putnbr_len(n))`: Finalmente, se retorna el resultado de la
// función `ft_putnbr_len`, que calcula la longitud del número impreso.

// En resumen, la función `ft_putnbr` imprime un número entero en la salida estándar,
// manejando los casos especiales como el número mínimo representable por un `int`.
// Utiliza recursión para imprimir cada dígito del número y calcula la longitud total
// del número impreso.
