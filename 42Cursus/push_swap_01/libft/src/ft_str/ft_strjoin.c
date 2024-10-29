/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:03:47 by michhern          #+#    #+#             */
/*   Updated: 2024/07/25 16:09:36 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_len;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new_str = (char *)malloc(sizeof(char) * new_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(new_str, s2, new_len);
	return (new_str);
}
