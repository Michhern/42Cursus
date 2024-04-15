/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:03:23 by michhern          #+#    #+#             */
/*   Updated: 2024/02/06 16:49:53 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			last = str;
		}
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return ((char *)last);
}

/*int	main(void)
{
	const char	str[] = "Laet's amake a test";
	const char	chr = '\0';

	printf("String after |%c| is - |%s|\n", chr, ft_strrchr(str, chr));
	return (0);
}*/
