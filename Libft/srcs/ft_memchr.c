/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:33:12 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:40:24 by micheher         ###   ########.fr       */
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
			return ((void *)&p_str[i]);
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