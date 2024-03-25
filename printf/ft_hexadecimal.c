/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:33 by michhern          #+#    #+#             */
/*   Updated: 2024/03/18 17:26:25 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned long long hexa, int *len, char format)
{
	if (hexa >= 16)
	{
		if (ft_hexadecimal(hexa / 16, len, format) == -1
			|| ft_hexadecimal(hexa % 16, len, format) == -1)
			return (-1);
	}
	else
	{
		if (hexa < 10)
		{
			if (ft_putchar(hexa + '0') == -1)
				return (-1);
		}
		else if (format == 'X')
		{
			if (ft_putchar(hexa - 10 + 'A') == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(hexa - 10 + 'a') == -1)
				return (-1);
		}
	}
	return (ft_hexalen(hexa, format));
}

// Esta función, `ft_hexadecimal`, convierte un número entero sin signo
// (`unsigned long long`) en su representación hexadecimal y lo imprime en
// la salida estándar. Aquí está su explicación paso a paso:
// 1. `unsigned long long hexa`: Este es el número entero sin signo que se
// convertirá a hexadecimal.

// 2. `int *len`: Es un puntero a un entero que representa la longitud total
// de la representación hexadecimal generada. Este parámetro se pasa como referencia,
// lo que significa que la función puede modificar su valor y este cambio será visible
// fuera de la función.

// 3. `char format`: Este parámetro indica si se debe usar la notación hexadecimal en
// mayúsculas (`'X'`) o minúsculas (`'x'`). Si `format` es `'X'`, la función imprimirá
// letras en mayúsculas; de lo contrario, imprimirá letras en minúsculas.
// La función comienza comparando `hexa` con 16. Si es mayor o igual a 16,
// esto significa que se necesitan dígitos adicionales para representar el número en
// hexadecimal y la función se llama recursivamente para procesar los dígitos restantes.

// 4. Dentro del bloque `if (hexa >= 16)`: 
// - La función se llama recursivamente dos veces, una vez para procesar el cociente de
// `hexa / 16` y otra para procesar el residuo de `hexa % 16`. Ambas llamadas buscan
// convertir los dígitos restantes a hexadecimal.
// - Si alguna de estas llamadas recursivas devuelve `-1`, indicando un error, la función
// principal también devuelve `-1`.

// 5. Dentro del bloque `else`:
// - Si el valor de `hexa` es menor que 10, significa que es un dígito hexadecimal simple (0-9).
// La función `ft_putchar` se utiliza para imprimir el carácter correspondiente (`'0'` a `'9'`).
// - Si `hexa` es mayor o igual a 10, significa que es un dígito hexadecimal en maúsculas
// (`'A'` a `'F'`) o en minúsculas (`'a'` a `'f'`). Dependiendo del valor de `format`,
// la función `ft_putchar` se utiliza para imprimir el carácter correspondiente en mayúsculas
// o minúsculas.

// 6. Después de imprimir el dígito hexadecimal actual, la función llama a `ft_hexalen` para
// actualizar el valor de `len`, que representa la longitud total de la representación
// hexadecimal generada.

// 7. La función finaliza retornando el resultado de `ft_hexalen`, que es la longitud total
// de la representación hexadecimal.

// En resumen, esta función convierte un número entero sin signo en su representación hexadecimal
// y la imprime en la salida estándar, utilizando recursión para procesar todos los dígitos.
// Además, actualiza un contador de longitud (`len`) que registra la cantidad de dígitos impresos.
// Si ocurre algún error durante el proceso de impresión, la función devuelve `-1`.
