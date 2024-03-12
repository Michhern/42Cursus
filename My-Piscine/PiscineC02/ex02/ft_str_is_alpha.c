/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:49 by michhern          #+#    #+#             */
/*   Updated: 2023/12/05 18:18:29 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_str_is_alpha(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		if ((str[c] < 'a' || str[c] > 'z')
			&& (str[c] < 'A' || str[c] > 'Z'))
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
	printf("%d", ft_str_is_alpha(argv[1]));
}*/
