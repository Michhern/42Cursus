/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:47:40 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:48:08 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

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
