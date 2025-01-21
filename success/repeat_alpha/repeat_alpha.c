/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:29 by michhern          #+#    #+#             */
/*   Updated: 2024/11/13 14:12:06 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	c;
	int		i;
	int		repeat;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			c = av[1][i];
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			{
				if (c >= 'A' && c <= 'Z')
					repeat = c - 'A';
				if (c >= 'a' && c <= 'z')
					repeat = c - 'a';
				while (repeat-- > 0)
					write(1, &c, 1);
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
