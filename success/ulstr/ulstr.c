/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:12:18 by michhern          #+#    #+#             */
/*   Updated: 2025/01/09 11:17:14 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		c;

	if (ac == 2)
	{
		str = av[1];
		c = 0;
		while (str[c])
		{
			if (str[c] >= 'A' && str[c] <= 'Z')
				str[c] += 32;
			else if (str[c] >= 'a' && str[c] <= 'z')
				str[c] -= 32;
			write(1, &str[c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
