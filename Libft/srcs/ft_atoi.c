/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:13:23 by micheher          #+#    #+#             */
/*   Updated: 2025/05/31 11:32:29 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sing;

	res = 0;
	sing = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (sing = '-')
		sing *= -1;
	if (*str =='-' || *str == '+')
		sing++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sing);
}

/*int main(int argc, char **argv)
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