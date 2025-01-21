/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:46:15 by michhern          #+#    #+#             */
/*   Updated: 2024/06/19 12:31:58 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 4 && av[2][1] == '\0' && av[3][1] == '\0')
	{
		while (*av[1])
		{
			if (*av[2] == *av[1])
				write(1, av[3], 1);
			else
				write(1, av[1], 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
	exit (0);
}
