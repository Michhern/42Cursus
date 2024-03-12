/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:13:53 by michhern          #+#    #+#             */
/*   Updated: 2023/12/06 16:37:45 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_str_is_printable(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] < 32 || str[c] > 126)
		{
			return (0);
		}
		c++;
	}
	return (1);
}

/*int	main(int argc, char **argv)
{
	argc = 0;
	printf("%d", ft_str_is_printable(argv[1]));
}*/
