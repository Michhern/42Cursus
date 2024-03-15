/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:47:01 by michhern          #+#    #+#             */
/*   Updated: 2024/01/26 20:31:55 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
	{
		write (fd, &str[c], 1);
		c++;
	}
	write (fd, "\n", 1);
}

/*int	main(void)
{
	ft_putstr_fd("Hi, let's do a test?", 1);
	return (0);
}*/
