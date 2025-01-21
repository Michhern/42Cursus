/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:29:59 by michhern          #+#    #+#             */
/*   Updated: 2024/12/13 12:46:57 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*int	main(void)
{
	char	str[] = "Hola, que tal";
	char	dest[50];
	
	ft_strcpy(dest, str);
	printf("Source: %s\n", str);
	printf("Destination: %s\n", dest);
	return (0);
}*/
