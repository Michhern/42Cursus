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
