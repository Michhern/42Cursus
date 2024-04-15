/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:03:42 by michhern          #+#    #+#             */
/*   Updated: 2024/03/20 18:54:03 by michhern         ###   ########.fr       */
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
