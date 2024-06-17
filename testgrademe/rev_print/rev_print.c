/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:14:14 by michhern          #+#    #+#             */
/*   Updated: 2024/06/17 16:57:36 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	rev;

	if (argc == 2)
	{
		rev = ft_strlen(argv[1]);
		while (rev--)
			write(1, &argv[1][rev], 1);
	}
	write(1, "\n", 1);
	return (0);
}
