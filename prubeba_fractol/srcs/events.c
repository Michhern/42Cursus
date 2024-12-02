/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:28:44 by michhern          #+#    #+#             */
/*   Updated: 2024/12/02 13:39:03 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
* ESC or i pres the x in the window
* there won't be leaks!
* int (*f)(void *param)
*/

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/*
* Keypress prototype
*int (*f)(int keycode, void *param)
*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
	{
		if (fractal->iterations_definition > 10)
			fractal->iterations_definition -= 10;
	}
	//frefresh the image
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	
	//Zoom in 
	if (button == Button5)
	{
		if (fractal->zoom > 0.01)
			fractal->zoom *= 0.95;
	}
	//Zoom out
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

/*
* TRACK the mouse
* to change Julia dynamiclly
* in (*f)(int x, int y, void *param)
*/
/*int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom)
			+ fractal->julia_x;
		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom)
			+ fractal->julia_y;
		fractal_render(fractal);
	}
	return (0);
}*/ //esta es la original

/*Version de la funcion anterior*/
int	julia_track(int x, int y, t_fractal *fractal)
{
	double	mapped_x;
	double	mapped_y;
	double	old_range_x;
	double	old_range_y;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return (0);
	old_range_x = WIDTH;
	old_range_y = HEIGHT;
	if (fractal->name && !ft_strncmp(fractal->name, "julia", 5))
	{
		mapped_x = map(x, -2.0, 2.0, old_range_x);
		mapped_y = map(y, 2.0, -2.0, old_range_y);
		fractal->julia_x += mapped_x;
		fractal->julia_y += mapped_y;
		fractal_render(fractal);
	}
	return (0);
}
