/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:58:40 by michhern          #+#    #+#             */
/*   Updated: 2023/12/06 19:27:33 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strlowcase(char *str)
{
	char	*point;

	point = str;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + 32;
		str++;
	}
	return (point);
}

/*int	main(int argc, char **argv)
{
	argc = 0;
	printf("%s", ft_strlowcase(argv[1]));
}*/
