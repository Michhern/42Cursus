/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:50:58 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 12:58:26 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *finder, size_t len)
{
	size_t	position;

	position = ft_strlen((char *)finder);
	if (*finder == '\0')
		return ((char *)str);
	while (*str != '\0' && len >= len >= position)
	{
		if (*str == *finder && ft_memcp(str, finder, position) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	haystack[] = "this's just a simulation, don't panic";
	char	needle[] = "just";
	char	*str;
	size_t	len = 37;

	str = ft_strnstr(haystack, needle, len);
	if (*str != '\0')
	{
		//resta direcciones de memoria
		printf("str: %p -- Haystack: %p\n", str, haystack); 
		printf("String to search found at position %ld: %s\n",
		 str - haystack, str);
	}
	else
	{
		printf("failed to find string!\n");
	}
	return (0);
}*/