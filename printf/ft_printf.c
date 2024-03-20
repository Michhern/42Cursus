/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:26:52 by michhern          #+#    #+#             */
/*   Updated: 2024/03/20 17:41:42 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printformat(char format, va_list args);

static int	ft_percent(char c, va_list arg)
{
	int	tmp;

	tmp = 0;
	if (c != '%')
	{
		tmp = ft_printformat(c, arg);
		if (tmp == -1)
			return (-1);
		return (tmp);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (-1);
		return (1);
	}
}

static int	ft_write_percent(const char *str, va_list arg, int n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			n += ft_percent(str[++i], arg);
			if (n == -1)
				return (-1);
		}
		else
		{
			if (write(1, &str[i], 1) != 1)
				return (-1);
			n++;
		}
		i++;
	}
	return (n);
}

static int	ft_printformat(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'X' || format == 'x')
		return (ft_hexadecimal(va_arg(args, unsigned int), &len, format));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (ft_hexadecimal(va_arg(args, unsigned long long), &len, format));
	}
	else if (format == 'u')
		return (ft_nbrunsig(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	n = 0;
	va_start(args, format);
	n = ft_write_percent(format, args, n);
	va_end(args);
	return (n);
}
