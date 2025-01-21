/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:04:52 by michhern          #+#    #+#             */
/*   Updated: 2025/01/16 12:03:04 by michhern         ###   ########.fr       */
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
		while (str[c] == ' ' || str[c] == '\t')
			c++;
		while (str[c] && (str[c] != ' ' && str[c] != '\t'))
		{
			write(1, &str[c], 1);
			c++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
