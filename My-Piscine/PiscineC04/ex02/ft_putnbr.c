/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:53:43 by michhern          #+#    #+#             */
/*   Updated: 2023/12/13 19:13:23 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	b;

	if (nb < 0)
		b = nb * -1;
	else
		b = nb;
	if (nb < 0)
		ft_putchar('-');
	if (b < 10)
	{
		ft_putchar(b + '0');
	}
	else
	{
		ft_putnbr(b / 10);
		ft_putnbr(b % 10);
	}
}

/*int	main(void)
{
	ft_putnbr(-2147483648);
}*/
