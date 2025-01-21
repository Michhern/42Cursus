/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:23:15 by michhern          #+#    #+#             */
/*   Updated: 2025/01/16 13:40:34 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	str_capitalizer(char *str)
{
	int	c;
	int	new;

	new = 1;
	c = 0;
	while (str[c])
	{
		if ((str[c] >= 'A' && str[c] <= 'Z') && !new)
			str[c] += 32;
		if ((str[c] >= 'a' && str[c] <= 'z') && new)
		{
			str[c] -= 32;
			new = 0;
		}
		else if (str[c] == ' ' || str[c] == '\t' || str[c] == '\0')
			new = 1;
		else
			new = 0;
		write(1, &str[c++], 1);
	}
}

int	main(int ac, char *av[])
{
	int	i;

	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < ac)
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
