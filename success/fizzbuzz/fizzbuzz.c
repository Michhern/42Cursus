/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:31:02 by michhern          #+#    #+#             */
/*   Updated: 2025/01/14 12:20:51 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	int	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

int	main(void)
{
	int		f;

	f = 1;
	while (f >= 1 && f <= 100)
	{
		if (f % 3 == 0 && f % 5 == 0)
			write (1, "fizzbuzz\n", 9);
		else if (f % 3 == 0)
			write (1, "fizz\n", 5);
		else if (f % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			ft_putnbr(f);
			write (1, "\n", 1);
		}
		f++;
	}
	return (0);
}
