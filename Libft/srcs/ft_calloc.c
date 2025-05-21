/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:00:43 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 13:04:19 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

/*int	main(void)
{
	int		val;
	char	str[20];

	strcpy(str, "98993489");
	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);
	strcpy(str, "Let's do a test");
	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);
	return (0);
}*/