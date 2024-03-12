/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:33 by michhern          #+#    #+#             */
/*   Updated: 2024/03/08 14:57:12 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthexa_long(char *longstr, unsigned long long n, int count)
{
	unsigned long long	len;

	if (!longstr)
		return (-1);
	len = ft_strlen(longstr);
	if (n >= len)
	{
		count = puthexa_long(longstr, n / len, count);
		if (count == -1)
			return (-1);
		if (write(1, &longstr[n % len], 1) == -1)
			return (-1);
		count++;
	}
	else if (n < len)
	{
		if (write (1, &longstr[n], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

static int	putexa_unsigint(char *str, unsigned int c, int i)
{
	unsigned long long	len;

	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (c >= len)
	{
		i = putexa_unsigint(str, c / len, i);
		if (i == -1)
			return (-1);
		if (write(1, &str[c % len], 1) == -1)
			return (-1);
		i++;
	}
	else if (c < len)
	{
		if (write (1, &str[c], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_hexa_upper(int u)
{
	int	hexa;

	hexa = 0;
	if (u >= 0)
		hexa = puthexa_long("0123456789ABCDEF", u, hexa);
	else
		hexa = putexa_unsigint("0123456789ABCDEF", u, hexa);
	return (hexa);
}

/*void	ft_hexadecimal(unsigned int hexa, int *len, char op)
{
	char	str[20];
	char	*base;
	int		i;
	int		index;

	i = 0;
	if (op == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (hexa == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (hexa != 0)
	{
		index = hexa % 16;
		str[i] = base [index];
		hexa = hexa / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}

void	ft_pointer(unsigned long pointer, int *len)
{
	char	str[20];
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (write(1, "0x", 2) < 0)
	{
		(*len) = -1;
		return ;
	}
	(*len) += 2;
	if (pointer == 0)
	{
		ft_putchar_len('0', len);
		return ;
	}
	while (pointer != 0)
	{
		str[i] = base[pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putchar_len(str[i], len);
}*/