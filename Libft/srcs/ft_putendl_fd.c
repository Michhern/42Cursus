/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:14:49 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 10:20:17 by micheher         ###   ########.fr       */
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