/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:15:05 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 15:38:51 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p_str;
	size_t			i;

	i = 0;
	p_str = (unsigned char *)str;
	while (i < n)
	{
		if (p_str[i] == (unsigned char)c)
		{
			return ((void *)&p_str[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	str[] = "Let's make a test";
	const char	chr = 's';
	char		*ret;

	ret = ft_memchr(str, chr, strlen(str));
	printf("String after |%c| is - |%s|\n", chr, ret);
	printf("%p\n", ret);
	return (0);
}*/
