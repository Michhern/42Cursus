/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:03:42 by michhern          #+#    #+#             */
/*   Updated: 2024/03/18 17:26:27 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned long long hexa, char format)
{
	unsigned long long	len;

	len = 0;
	while (hexa / 16 != 0)
	{
		len++;
		hexa /= 16;
	}
	len++;
	if (format == 'p')
		return (len + 2);
	return (len);
}


// 1. `unsigned long long hexa`: Este es el número entero sin signo que se está
// convirtiendo a hexadecimal.

// 2. `char format`: Este parámetro indica el formato de salida deseado.
// En este caso, se utiliza para determinar si el número representa una dirección
// de memoria (`'p'`).

// La función `ft_hexalen` calcula la longitud de la representación hexadecimal
// del número `hexa`.

// El proceso se desarrolla de la siguiente manera:

// - `unsigned long long len`: Esta variable se inicializa en 0 y se utilizará para
// almacenar la longitud de la representación hexadecimal del número `hexa`.

// - El bucle `while (hexa / 16 != 0)` se ejecuta mientras el cociente de dividir
// `hexa` por 16 no sea igual a cero. Esto significa que el número `hexa` aún tiene
// dígitos hexadecimales que deben ser contados. En cada iteración del bucle:
//   - Se incrementa `len` en 1 para contar el dígito hexadecimal.
//   - `hexa` se divide por 16 para pasar al siguiente dígito hexadecimal.

// - Después de salir del bucle, `len` se incrementa en 1 más. Esto se debe a que el
// bucle se detiene cuando `hexa / 16` es cero, lo que significa que aún queda un
// dígito por contar.

// - Si el formato es `'p'` (una dirección de memoria), se devuelve `len + 2`.
// Esto se debe a que las direcciones de memoria suelen tener el prefijo `"0x"`,
// por lo que se agregan dos caracteres adicionales a la longitud total.

// - Si el formato no es `'p'`, simplemente se devuelve `len`, que representa
// la longitud de la representación hexadecimal sin ningún prefijo adicional.

// En resumen, la función `ft_hexalen` calcula la longitud de la representación
// hexadecimal de un número, teniendo en cuenta si se trata de una dirección
// de memoria. Devuelve la longitud total de la representación hexadecimal,
// incluyendo cualquier prefijo adicional necesario.
