/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:59:02 by michhern          #+#    #+#             */
/*   Updated: 2025/01/10 14:00:45 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*strcpy;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	strcpy = malloc(sizeof(*strcpy) * (len + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}

/*int	main(int ac, char *av[])
{
	char	*str;
	char	*copy;

	if (ac == 2)
	{
		str = av[1];
		copy = ft_strdup(str);
		if (copy != NULL)
		{
			printf("Original: %s\n", str);
			printf("Copia: %s\n", copy);
			free(copy);
		}
		else
			printf("Error, no se pudo asignar memoria.\n");
	}
	else
		printf("Error: %s <string>\n", av[0]);
	return (0);
}*/
