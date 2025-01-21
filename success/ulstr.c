/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:12:33 by michhern          #+#    #+#             */
/*   Updated: 2024/12/30 12:08:50 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		c;

	c = 0;
	str = av[1];
	if (ac == 2)
	{
		while (str[c])
		{
			if (str[c] >= 'a' && str[c] <= 'z')
				str[c] -= 32;
			else if (str[c] >= 'A' && str[c] <= 'Z')
				str[c] += 32;
			write(1, &str[c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
