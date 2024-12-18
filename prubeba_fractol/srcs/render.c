/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:34:17 by michhern          #+#    #+#             */
/*   Updated: 2024/12/02 12:58:31 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
* Put a pixel in my image buffer
*/
/*static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}*/

/*Nueva implementacion*/
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *)(img->pixels_ptr + offset) = color;
	}
}

/*
* EASY TOGGLE mandel & julia
*/
/*static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}*/
/*Nueva implementacon*/
static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->type == FRACTAL_JULIA)
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/*
 * 						 ✅ map()
		   	0__________800     -2___________+2    
 *			|			 |     |            |
 *			|			 |	   |            |
 *		800	|			 |     |            |
 *			|			 |     |            |
 *			|			 |     |            |
 *			|____________|     |____________|

 *	
 *		MANDELBROT
 *		z = z^2 + c
 *		z initially is (0, 0)
 *		c is the actual point
 *
 *		z = z^2 + c -> z1 = c + c
 *
 *		JULIA
 *		./fractol julia <real> <i> 
 *		z = pixel_point + constant
*/
static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	//pixel coordinate x && y scaled to fit mandel needs
	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	//How many time you want to iterate z^2 + c to check if the point escaped?
	while (i < fractal->iterations_definition)
	{
		//actual z^2 + c
		// z = z^2 + c
		z = sum_complex(square_complex(z), c);
		// Is the value escaped??
		// If hypotense > 2 i asume the point has escaped
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	// we are in MANDELBROT given the iterations made
	my_pixel_put(x, y, &fractal->img, WHITE);
}

/*
 * Actual 🍖
 *
 * 				
 *		   	____800_______
 *			|			 |
 *			|			 |
 *		800	|			 |
 *			|			 |
 *			|			 |
 *			|____________|
*/
/*void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_windows, fractal->img.img_ptr, 0, 0);
}*/

/*Nueva implementacion*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_windows, fractal->img.img_ptr, 0, 0);
}
