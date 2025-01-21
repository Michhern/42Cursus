/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:07 by michhern          #+#    #+#             */
/*   Updated: 2025/01/07 12:24:28 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int ac, char *av[])
{
	int		rev;
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		rev = ft_strlen(str);
		while (rev--)
			write(1, &str[rev], 1);
	}
	write(1, "\n", 1);
	return (0);
}
