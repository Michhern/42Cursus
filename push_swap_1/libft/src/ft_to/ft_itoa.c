/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:42:10 by michhern          #+#    #+#             */
/*   Updated: 2024/08/08 13:55:17 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	digit_count(int d)
{
	int	c;
	int	temp;

	c = 1;
	temp = d;
	if (temp < 0)
	{
		temp *= -1;
		c++;
	}
	while (temp >= 10)
	{
		temp /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		idx;
	int		count;
	char	*rest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	idx = digit_count(n);
	rest = (char *)malloc((sizeof(char)) * (idx + 1));
	count = n;
	if (!rest)
		return (0);
	rest[idx--] = 0;
	if (count < 0)
	{
		rest[0] = '-';
		count *= -1;
	}
	while (count > 0)
	{
		rest[idx--] = count % 10 + '0';
		count /= 10;
	}
	return (rest);
}
