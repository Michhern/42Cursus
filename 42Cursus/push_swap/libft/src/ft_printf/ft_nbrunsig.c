/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:48:55 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:49:26 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

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
