/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:46:16 by michhern          #+#    #+#             */
/*   Updated: 2024/05/02 12:14:22 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		pos;
	char	*str;

	pos = 0;
	str = argv[1];
	if (argc == 2)
	{
		while (str[pos])
		{
			if (str[pos] >= 'A' && str[pos] <= 'Z')
			{
				str[pos] += 32;
				write (1, "_", 1);
			}
			write(1, &str[pos], 1);
			pos++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
