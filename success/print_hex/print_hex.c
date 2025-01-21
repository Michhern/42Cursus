/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:18:15 by michhern          #+#    #+#             */
/*   Updated: 2025/01/03 13:48:16 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	atoi(char *ptr)
{
	int	n;

	n = 0;
	while (*ptr != '\0')
	{
		n = n * 10;
		n = n + *ptr - '0';
		++ptr;
	}
	return (n);
}

void	print_hex(int n)
{
	char	*digit;

	digit = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	write(1, &digit[n % 16], 1);
}

int	main(int ac, char *av[])
{
	char	*str;

	str = av[1];
	if (ac == 2)
		print_hex(atoi(str));
	write(1, "\n", 1);
}
