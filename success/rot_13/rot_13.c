/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:24:47 by michhern          #+#    #+#             */
/*   Updated: 2025/01/17 12:39:27 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*str;
	int		r;

	str = av[1];
	r = 0;
	if (ac == 2)
	{
		while (str[r])
		{
			if ((str[r] >= 'A' && str[r] <= 'M')
				|| (str[r] >= 'a' && str[r] <= 'm'))
				str[r] += 13;
			else if ((str[r] >= 'N' && str[r] <= 'Z')
				|| (str[r] >= 'n' && str[r] <= 'z'))
				str[r] -= 13;
			write(1, &str[r++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
