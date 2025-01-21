/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:34:46 by michhern          #+#    #+#             */
/*   Updated: 2024/06/13 15:07:43 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	sing;

	res = 0;
	sing = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sing *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sing);
}

/*int	main(int argc, char **argv)
{
	int	str1;
	int	str2;

	if (argc == 2)
	{
		str1 = ft_atoi(argv[1]);
		str2 = atoi(argv[1]);
		printf ("str1: %d | str2: %d\n", str1, str2);
	}
	return (0);
}*/
