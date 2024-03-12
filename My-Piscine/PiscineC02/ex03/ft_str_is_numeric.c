/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:05:28 by michhern          #+#    #+#             */
/*   Updated: 2023/12/05 18:29:07 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_str_is_numeric(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < '0' || str[n] > '9')
		{
			return (0);
		}
		n++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "1234567";

	printf("%i", ft_str_is_numeric(str));
	return (0);
}*/
