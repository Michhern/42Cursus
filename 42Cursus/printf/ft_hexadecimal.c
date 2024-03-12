/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:33 by michhern          #+#    #+#             */
/*   Updated: 2024/03/12 12:22:29 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadecimal(unsigned int hexa, int *len, char format)
{
	if (hexa >= 16)
	{
		if (ft_hexadecimal(hexa / 16, len, format) == -1 
			|| ft_hexadecimal(hexa % 16, len, format) == -1)
			return (-1)
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
		return ()
	}
}
