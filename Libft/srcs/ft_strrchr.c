/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:25:11 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:38:38 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == (char) c)
			last = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return ((char *)last);
}

/*int	main(void)
{
	const char	str[] = "Laet's amake a test";
	const char	chr = '\0';

	printf("String after |%c| is - |%s|\n", chr, ft_strrchr(str, chr));
	return (0);
}*/