/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:12:09 by michhern          #+#    #+#             */
/*   Updated: 2024/06/18 15:57:38 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	pos;

	pos = 0;
	if (ac == 2)
	{
		while (av[1][pos] != '\0')
		{
			if ((av[1][pos] >= 'a' && av[1][pos] <= 'y')
				|| (av[1][pos] >= 'A' && av[1][pos] <= 'Y'))
				av[1][pos] += 1;
			else if (av[1][pos] == 'z' || av[1][pos] == 'Z')
				av[1][pos] -= 25;
			write(1, &av[1][pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
