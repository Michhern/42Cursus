/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:34:27 by michhern          #+#    #+#             */
/*   Updated: 2024/03/20 18:40:26 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrunsig(unsigned int n)
{
	if (n < 10)
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_nbrunsig(n / 10) == -1 || ft_nbrunsig(n % 10) == -1)
			return (-1);
	}
	return (ft_putnbr_len_unsigned(n));
}


// La función `ft_nbrunsig` imprime un número entero sin signo (`unsigned int`)
// en la salida estándar. Aquí tienes un análisis paso a paso de cómo funciona:

// 1. `int ft_nbrunsig(unsigned int n)`: Esta es la definición de la función
// `ft_nbrunsig`, que toma un número entero sin signo como argumento.

// 2. `if (n < 10) { ... }`: Se verifica si el número es menor que 10. Si es así,
// significa que es un solo dígito y puede ser impreso directamente.

//    - `if (ft_putchar(n + '0') == -1)`: Se utiliza `ft_putchar` para imprimir
// 	el dígito en la salida estándar. Si hay algún error al imprimir el dígito,
// 	la función devuelve `-1`.

// 3. `else { ... }`: Si el número es mayor o igual a 10, significa que tiene
// más de un dígito y debe ser dividido en partes más pequeñas.

//    - `if (ft_nbrunsig(n / 10) == -1 || ft_nbrunsig(n % 10) == -1)`:
// 	La función se llama recursivamente dos veces:
//      - Una vez con el cociente de la división entera de `n / 10`,
// 	lo que significa que se está tratando el dígito de más a la izquierda.
//      - Otra vez con el resto de la división de `n % 10`, que representa el último
// 	dígito del número.
//      - Si hay algún error al imprimir alguno de estos dígitos,
// 	la función devuelve `-1`.

// 4. `return (ft_putnbr_len_unsigned(n));`: Después de imprimir todos los dígitos
// correctamente, la función retorna la longitud total del número impreso,
// utilizando la función `ft_putnbr_len_unsigned` para calcularla.

// En resumen, la función `ft_nbrunsig` imprime un número entero sin signo
// en la salida estándar, manejando recursivamente los dígitos del número.
// Si ocurre algún error durante la impresión, la función devuelve `-1`.
