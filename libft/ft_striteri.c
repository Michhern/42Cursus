/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:55:53 by michhern          #+#    #+#             */
/*   Updated: 2024/02/12 13:18:14 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	print_indx_char(unsigned int indx, char *car)
{
	printf("Indice: %u, Caracter: %s\n", indx, car);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	indx;

	if (!s || !f)
		return ;
	indx = 0;
	while (s[indx])
	{
		f(indx, s + indx);
		indx++;
	}
}

/*int	main(void)
{
	char	str[] = "Hello";

	ft_striteri(str, &print_indx_char);
	return (0);
}*/