/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:12:40 by michhern          #+#    #+#             */
/*   Updated: 2024/08/07 12:27:46 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
