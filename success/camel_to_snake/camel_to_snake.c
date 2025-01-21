/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:03:28 by michhern          #+#    #+#             */
/*   Updated: 2025/01/16 12:22:24 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		c;

	str = av[1];
	c = 0;
	if (ac == 2)
	{
		while (str[c])
		{
			if (str[c] >= 'A' && str[c] <= 'Z')
			{
				str[c] += 32;
				write(1, "_", 1);
			}
			write(1, &str[c++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
