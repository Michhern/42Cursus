/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:49:49 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 09:54:43 by micheher         ###   ########.fr       */
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
	char	str[] = "hello";
	ft_striteri(str, &print_indx_char);
	return (0);
}*/