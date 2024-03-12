/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:11:21 by michhern          #+#    #+#             */
/*   Updated: 2023/12/11 19:08:38 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i] && i < n - 1)
		{
			i++;
		}
		return (s1[i] - s2[i]);
	}
	return (0);
}

/*int	main(void)
{
	char	str1[4] = "Hola";
	char	str2[7] = "Holanda";
	unsigned int	n;
	int		result;

	n = 4;
	result = ft_strncmp(str1, str2, n);
	if (result == 0)
	{
		printf("las primeras %u letras son iguales.\n", n);
	}
	else if (result < 0)
	{
		printf("Las 1ras %u letras del string 1 son < 2.\n", n);
	}
	else
	{
		printf("Las 1as %u letras del etr 1 son > 2.\n", n);
	}
	return (0);
}*/
