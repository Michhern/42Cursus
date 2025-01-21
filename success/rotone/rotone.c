/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:57:31 by michhern          #+#    #+#             */
/*   Updated: 2024/12/09 11:21:33 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		pos;

	str = av[1];
	pos = 0;
	if (ac == 2)
	{
		while (str[pos] != '\0')
		{
			if ((str[pos] >= 'a' && str[pos] <= 'y')
				|| (str[pos] >= 'A' && str[pos] <= 'Y'))
				str[pos] += 1;
			else if (str[pos] == 'z' || str[pos] == 'Z')
				str[pos] -= 25;
			write(1, &str[pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
