/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:50:51 by michhern          #+#    #+#             */
/*   Updated: 2024/04/25 14:54:44 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*str;
	int		c;

	while (argc != 2)
	{
		write(1, "\n", 1);
			return (0);
	}
	str = argv[1];
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] >= 'a' && str[c] <= 'z')
		{
			str[c] -= 32;
		}
		else if (str[c] >= 'A' && str[c] <= 'Z')
		{
			str[c] += 32;
		}
		write(1, &str[c], 1);
		c++;
	}
	write(1, "\n", 1);
	return (0);
}
