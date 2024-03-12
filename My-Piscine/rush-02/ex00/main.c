/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:46:28 by michhern          #+#    #+#             */
/*   Updated: 2023/12/10 19:39:34 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unisted.h>

int	main(int argc, char **argv)
{
	char	buffer[1000];
	int		numb;

	if (argc < 2 || argc > 3)//Verificamos si el numero de arguments es menos que 2 o mayor que 3.
		write(1, "Error\n", 6);
	if(agc == 2)
	{
		if (!ft_numb(argv[1], "numbers.dict"))//Verificamos la funcion ft_numb con los argv y el number.dicts .
			write(1, "Error\n", 6);
	}
	if (agrc == 3)
	{
		if (!ft_numb(argv[2], argv[1]))//Verificamos la funcion com los argv 2 y 1 .
			write(1, "Error\n", 6)
	}
	return (0);
}
