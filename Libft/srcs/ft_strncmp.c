/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:31:16 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:32:19 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			cmp;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cmp = 0;
	if (n > 0)
	{
		while ((str1[cmp] != '\0' && str2[cmp] != '\0')
			&& str1[cmp] == str2[cmp] && cmp < n - 1)
		{
			cmp++;
		}
		return (str1[cmp] - str2[cmp]);
	}
	return (0);
}

/*int	main(void)
{
	char	str1[8] = "Fernando";
	char	str2[10] = "Fernandez";
	size_t	n;
	size_t	result;

	n = 5;
	result = ft_strncmp(str1, str2, n);
	if (result == 0)
	{
		printf("las primeras %zu letras son iguales.\n", n);
	}
	else if (result < 0)
	{
		printf("Las 1ras %zu letras del string 1 son < 2.\n", n);
	}
	else
	{
		printf("Las 1as %zu letras del string 1 son > 2.\n", n);
	}
	return (0);
}*/