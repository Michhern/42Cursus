/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:29:10 by michhern          #+#    #+#             */
/*   Updated: 2024/04/23 14:51:07 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/*int	main(void)
{
	char	*str;
	int		len;

	str = "Hi, fuck u";
	len = ft_strlen(str);
	printf("Len of the string: %d\n", len);
	return (0);
}*/
