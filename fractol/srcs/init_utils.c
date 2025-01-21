/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:41:37 by michhern          #+#    #+#             */
/*   Updated: 2024/12/10 20:13:27 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	malloc_error(const char *context)
{
	if (context)
		fprintf(stderr, "Error during the %s: ", context);
	perror("malloc");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escape_value = DEFAULT_ESCAPE_VALUE;
	fractal->iterations_definition = DEFAULT_ITERATIONS;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = DEFAULT_ZOOM;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_windows,
		KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->mlx_windows, ButtonPress,
		ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->mlx_windows, DestroyNotify,
		StructureNotifyMask, close_handler, fractal);
	mlx_hook(fractal->mlx_windows, MotionNotify,
		PointerMotionMask, julia_track, fractal);
}
