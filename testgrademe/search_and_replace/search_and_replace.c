/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_add_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:11:38 by michhern          #+#    #+#             */
/*   Updated: 2024/04/17 14:24:35 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 4)
	{
		write(1, "\n", 1);
		exit (0);
	}
	if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	exit (0);
}
