/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:51:08 by michhern          #+#    #+#             */
/*   Updated: 2024/12/02 13:39:03 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*Project
*
*~Julia and Mandelbrot
*~Zoom infinito
*~Capaz de tomar argumentos de la línea de comandos para disiplinar que
*	fractal renderizar
*~Puede tomar args de la linea de comandos para dar forma a Julia,
* es decir, coordenadas x e y

*~ESC cierra el proceso sin fugas
*~Click en la ventana X, cierra el proceso sin fugas
*
*El código tiene que ser norminetted
*~Hay comentarios en todas partes para mayor claridad
*~i siempre ir en la siguiente línea para ver mejor las entradas de función
*~tldr->Don't git clone and push
*
*/

/*
* I have 2 Kinda Prompts
*	~./fractol mandelbrot
*	~./fractol Julia <real> <i>
* The main function is a TL,DR of the application
*/

#include "../inc/fractol.h"

/*int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(av[2]);
			fractal.julia_y = atodbl(av[3]);
		}
		//TL;DR
		//Prompt correct, kick off the application
		//1)
		fractal_init(&fractal);
		//2
		fractal_render(&fractal);
		//3
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}*/

/*Version de la funcion anterior*/

int	main(int ac, char **av)
{
	t_fractal fractal;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		fractal.type = FRACTAL_MANDELBROT;
	else if (4 == ac && !ft_strncmp(av[2], "julia", 5))
	{
		fractal.type = FRACTAL_JULIA;
		fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
	}
	else
		exit(EXIT_FAILURE);
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
