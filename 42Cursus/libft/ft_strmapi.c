/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:59:43 by michhern          #+#    #+#             */
/*   Updated: 2024/02/08 14:37:03 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	add_one(unsigned int indx, char car)
{
	return (car + 1);
}*/

/*static char	to_upper(unsigned int indx, char car)
{
	if (car >= 'a' && car <= 'z')
	{
		return (car - 32);
	}
	else
	{
		return (car);
	}
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	size_t			len;
	char			*c;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		c[idx] = f(idx, s[idx]);
		idx++;
	}
	c[idx] = '\0';
	return (c);
}

/*int	main(void)
{
	const char	*input;
	char		(*f)(unsigned int, char);
	char		*result;


	input = "Hello";
	f = to_upper;
	result = ft_strmapi(input, f);

	if (result)
	{
		printf("Resultado: %s\n", result);
		free(result); // Liberar la memoria asignada dinámicamente
	}
	else
	{
		printf("Error: No se pudo asignar memoria.\n");
	}
	return (0);
}*/