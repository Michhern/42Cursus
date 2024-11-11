/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:51:08 by michhern          #+#    #+#             */
/*   Updated: 2024/11/11 14:16:05 by michhern         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10)
		|| 4 == ac && ! ft_strncmp(av[1], "Julia", 5))
	{
		//
		//prompt correct, kick oof the application
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}
