/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:34 by michhern          #+#    #+#             */
/*   Updated: 2024/12/02 13:39:03 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
/*
* If Malloc goes bad (improbable)
*/
/*static void	malloc_error(void)
{
	perror("problems whith malloc");
	exit(EXIT_FAILURE);
}*/

/*version de la funcion anterior*/
static void malloc_error(const char * context)
{
	if (context)
		fprintf(stderr, "Error during the %s: ", context);
	perror("malloc");
	exit(EXIT_FAILURE);
}

/*static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4; // 2 ^ 2, my hypotenuse
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	// zoom factor
	fractal->zoom = 1.0;
}*/
/*version de la funcion anterior*/
static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = DEFAULT_ESCAPE_VALUE;
	fractal->iterations_definition = DEFAULT_ITERATIONS;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = DEFAULT_ZOOM;
}

static void	events_init(t_fractal *fractal)
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

static void cleanup(t_fractal *fractal)
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
/*
	INIT
	~mlx
	~listening events
	~hooks data
*/

/*void	fractal_init(t_fractal *fractal)
{
	//MLX stuff
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error();
	fractal->mlx_windows = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_windows)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}*/
/*version de la funcion anterior*/

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (NULL == fractal->mlx_connection)
		malloc_error("initializing mlx_connection");
	fractal->mlx_windows = mlx_new_window(fractal->mlx_connection,
		WIDTH, HEIGHT, fractal->name);
	if (NULL == fractal->mlx_windows)
	{
		cleanup(fractal);
		malloc_error("creating mlx_window");
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
		&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.pixels_ptr)
	{
		cleanup(fractal);
		malloc_error("getting image data address");
	}
	events_init(fractal);
	data_init(fractal);
}
