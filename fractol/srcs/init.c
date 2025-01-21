/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:02:56 by michhern          #+#    #+#             */
/*   Updated: 2024/12/10 19:45:36 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	cleanup(t_fractal *fractal)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	if (fractal->mlx_windows)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
}

static void	initialize_window_and_image(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
	{
		fprintf(stderr, "Error: mlx_init() failed. \n");
		exit(EXIT_FAILURE);
	}
	fractal->mlx_windows = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_windows)
	{
		fprintf(stderr, "Error: mlx_new_image() failed.\n");
		cleanup(fractal);
		exit(EXIT_FAILURE);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		cleanup(fractal);
		malloc_error("Creating mlx_image");
	}
}

static void	initialize_image_data(t_fractal *fractal)
{
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.pixels_ptr)
	{
		cleanup(fractal);
		malloc_error("Getting image data address");
	}
	events_init(fractal);
	data_init(fractal);
}

void	fractal_init(t_fractal *fractal)
{
	initialize_window_and_image(fractal);
	initialize_image_data(fractal);
}
