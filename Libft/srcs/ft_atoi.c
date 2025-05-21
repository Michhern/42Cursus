/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:59:03 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:59:56 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*int	main(void)
{
	printf("%s\n", ft_itoa(100));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(0));
	return (0);
}*/