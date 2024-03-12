/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:16:40 by michhern          #+#    #+#             */
/*   Updated: 2024/03/08 15:25:24 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
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
	return (1);
}

/*int	ft_putnbr(int n)
{
	int	num;

	num = 0;
	if (n == -2147483648)
		return (ft_valminint(n));
	if (n < 0 && ++num)
	{
		if (write (1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 10)
	{
		num += ft_putnbr(n / 10);
		if (num == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 10)
	{
		if (ft_putchar(('0' + n)) == -1)
			return (-1);
		num++;
	}
	return (num);
}*/
