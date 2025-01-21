/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:09:11 by michhern          #+#    #+#             */
/*   Updated: 2024/12/10 17:19:36 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		fractal.type = FRACTAL_MANDELBROT;
	else if (4 == ac && !ft_strncmp(av[1], "julia", 5))
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
