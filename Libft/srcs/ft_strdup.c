/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:04:45 by micheher          #+#    #+#             */
/*   Updated: 2025/05/21 13:10:33 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*int	main(void)
{
	char	*string;
	char	*newstr;

	string = "this's a copy";
	newstr = ft_strdup(string);
	// Make newstr point to a duplicate of string
	if (newstr != NULL)
	{
		printf("The new string is: %s\n", newstr);
		free(newstr);
	}
	return (0);
}*/