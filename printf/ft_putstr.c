/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:09 by michhern          #+#    #+#             */
/*   Updated: 2024/03/20 17:05:49 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}



// 1. `int ft_putstr(char *str)`: Esta función toma una cadena de caracteres
// como entrada y la imprime en la salida estándar.

// 2. `int i = 0;`: Se inicializa una variable `i` que se usará como índice
// para recorrer la cadena de caracteres.

// 3. `if (!str) { ... }`: Se verifica si la cadena de caracteres es nula.
// Si es así, significa que no hay caracteres para imprimir. En este caso,
// se imprime la cadena `"(null)"` utilizando la función `write` y se retorna
// la longitud de la cadena (`6`, la longitud de `"(null)"`).

// 4. `while (str[i]) { ... }`: Se inicia un bucle while que recorre la cadena
// de caracteres hasta encontrar el carácter nulo (`'\0'`), que marca el final
// de la cadena.

// 5. `if (ft_putchar(str[i]) == -1) { ... }`: En cada iteración del bucle,
// se llama a la función `ft_putchar` para imprimir el carácter actual de la cadena.
// Si `ft_putchar` devuelve `-1`, indica un error, y la función `ft_putstr`
// también devuelve `-1`.

// 6. `i++;`: Se incrementa el índice `i` para pasar al siguiente carácter de la cadena.

// 7. Después de salir del bucle, se devuelve `i`, que representa la longitud
// total de la cadena de caracteres impresa.

// En resumen, la función `ft_putstr` imprime una cadena de caracteres en
// la salida estándar. Si la cadena es nula, imprime `"(null)"`, y si hay algún error
// durante la impresión de los caracteres, devuelve `-1`.
