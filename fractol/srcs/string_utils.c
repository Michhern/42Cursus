/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:28:58 by michhern          #+#    #+#             */
/*   Updated: 2024/12/11 16:57:53 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

long	parse_integer_part(char **s)
{
	long	integer_part;

	integer_part = 0;
	while (**s >= '0' && **s <= '9')
		integer_part = (integer_part * 10) + (*(*s)++ - '0');
	return (integer_part);
}

double	parse_fractional_part(char **s)
{
	double	fractional_part;
	double	divisor;

	fractional_part = 0;
	divisor = 1.0;
	if (**s == '.')
	{
		++(*s);
		while (**s >= '0' && **s <= '9')
		{
			divisor *= 10;
			fractional_part += (*(*s) - '0') / divisor;
			(*s)++;
		}
	}
	return (fractional_part);
}

double	atodbl(char *s)
{
	double	fractional_part;
	long	integer_part;
	int		sign;

	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		++s;
	}
	integer_part = parse_integer_part(&s);
	fractional_part = parse_fractional_part(&s);
	return (sign * (integer_part + fractional_part));
}
