/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:46:34 by michhern          #+#    #+#             */
/*   Updated: 2024/07/29 11:47:21 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

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
