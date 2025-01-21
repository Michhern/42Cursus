/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:05:47 by michhern          #+#    #+#             */
/*   Updated: 2024/12/19 18:55:11 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		i;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = av[1];
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 'z' - (str[i] - 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 'Z' - (str[i] - 'A');
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
