/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:02:42 by michhern          #+#    #+#             */
/*   Updated: 2023/12/06 16:39:13 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_str_is_uppercase(char *str)
{
	int	m;

	m = 0;
	while (str[m] != '\0')
	{
		if (str[m] < 65 || str[m] > 90)
		{
			return (0);
		}
		m++;
	}
	return (1);
}

/*int	main(int argc, char **argv)
{
	argc = 0;
	printf("%d", ft_str_is_uppercase(argv[1]));
}*/
