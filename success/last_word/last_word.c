/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:39:40 by michhern          #+#    #+#             */
/*   Updated: 2025/01/17 13:06:59 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		l;
	int		last;

	str = av[1];
	l = 0;
	last = 0;
	if (ac == 2)
	{
		while (str[l])
		{
			if (str[l] == 32 && (str[l + 1] >= 32 && str[l + 1] <= 126))
				last = l + 1;
			l++;
		}
		while (str[last] >= 33 && str[last] <= 126)
			write(1, &str[last++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
