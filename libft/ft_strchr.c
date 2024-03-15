/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:55:43 by michhern          #+#    #+#             */
/*   Updated: 2024/01/23 18:23:23 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*str == '\0' && (char)c == '\0')
		return ((char *)str);
	return (NULL);
}

/*int	main(void)
{
	const char	str[] = "Let's make a test";
	const char	chr = 'm';

	printf("String after |%c| is - |%s|\n", chr, ft_strchr(str, chr));
	return (0);
}*/
