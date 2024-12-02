/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:15:11 by michhern          #+#    #+#             */
/*   Updated: 2024/12/02 12:54:39 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	// Char are basically 1 byte int
	// when 0, strings are equal !!
	return (*s1 - *s2);
}*/

/*Nueva implementacion*/
int	ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}

/*void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}*/
/*Nueva implementacion*/
void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		++s;
	}
}

/*double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sing;

	integer_part = 0;
	fractional_part = 0;
	sing = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
	{
		if ('-' == *s++)
			sing = - sing;
	}
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sing);
}*/

/*Nueva implementacio*/
long	parse_integer_part(char **s)
{
	long	integer_part;

	integer_part = 0;
	while (**s >= '0' && **s <= '9') // Parte entera
		integer_part = (integer_part * 10) + (*(*s)++ - '0');
	return integer_part;
}

double	parse_fractional_part(char **s)
{
	double	fractional_part;
	double	divisor;
	
	fractional_part = 0;
	divisor = 1.0;
	if (**s == '.') // Parte fraccionaria
	{
		++(*s); // Saltar el punto
		while (**s >= '0' && **s <= '9')
		{
			fractional_part += (*(*s)++ - '0') / (divisor *= 10);
		}
	}
	return fractional_part;
}

double	atodbl(char *s)
{
	double fractional_part;
	long integer_part;
	int sign;
	
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ') // Saltar espacios
	++s;

	if (*s == '+' || *s == '-') // Manejar el signo
	{
		if (*s == '-') sign = -1;
		++s;
	}
	integer_part = parse_integer_part(&s); // Parte entera
	fractional_part = parse_fractional_part(&s); // Parte fraccionaria
	return (sign * (integer_part + fractional_part));
}
