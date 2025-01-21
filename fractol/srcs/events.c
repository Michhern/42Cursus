/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:56:13 by michhern          #+#    #+#             */
/*   Updated: 2025/01/09 12:54:05 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_windows);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

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
	else if (keysym == XK_equal)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
	{
		if (fractal->iterations_definition > 10)
			fractal->iterations_definition -= 10;
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		if (fractal->zoom > 0.01)
			fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

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
