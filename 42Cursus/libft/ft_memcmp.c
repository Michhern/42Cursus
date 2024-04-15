/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:34:59 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 15:07:19 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str1[15];
	char	str2[15];
	int		ret;

	memcpy(str1, "128456", 6);
	memcpy(str2, "124567", 6);
	ret = ft_memcmp(str1, str2, 5);
	if (ret > 0)
	{
		printf("str2 is less than str1");
	}
	else if (ret < 0)
	{
		printf("str1 is less than str2");
	}
	else
	{
		printf("str1 is equal to str2");
	}
	return (0);
}*/
