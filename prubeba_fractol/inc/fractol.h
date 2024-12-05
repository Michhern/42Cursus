/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:52:38 by michhern          #+#    #+#             */
/*   Updated: 2024/12/05 13:48:13 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //to do debugging
# include <stdlib.h> //malloc free
# include <unistd.h> //write
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \
	\n\t\"./fractol julia <value_1> <value_2>\"\n"

/*
	We use a ssquere to
	keep the rendering math simple
*/
# define WIDTH	800
# define HEIGHT	800

/*
	COLORS
*/
# define BLACK	0x000000  // RGB(0, 0, 0)
# define WHITE	0xFFFFFF  // RGB(255, 255, 255)
# define RED		0xFF0000  // RGB(255, 0, 0)
# define GREEN	0x00FF00  // RGB(0, 255, 0)
# define BLUE	0x0000FF  // RGB(0, 0, 255)

//Psychedelic colors
# define MAGENTA_BURST	0xFF00FF  // A vibrant magenta
# define LIME_SHOCK		0xCCFF00  // A blinding lime
# define NEON_ORANGE		0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM		0x33CCCC  // A bright turquoise
# define HOT_PINK		0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE	0x0066FF  // A radiant blue
# define LAVA_RED		0xFF3300  // A bright, molten red

/*
* Valores iniciale
*/
# define DEFAULT_ESCAPE_VALUE 4.0
# define DEFAULT_ITERATIONS 42
# define DEFAULT_ZOOM 1.0
# define FRACTAL_JULIA 1
# define FRACTAL_MANDELBROT 2

/*
* COMPLEX value
*/
typedef struct s_complex
{
	// real
	double	x;
	// i
	double	y;
}			t_complex;

/*
	IMAGE
	THIS is basically a pixels buffer
	values from mlx_get_data_addr()
*/
typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //pointer to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;
/*
	Fractal ID
	~ MLX stuff
	~ Image
	~ Hooks values
*/
typedef struct s_fractal
{
	int		type; //nuva
	char	*name;
	//MLX
	void	*mlx_connection; // mlx_init()
	void	*mlx_windows;	// mlx_new_windows()
	//Image
	t_img	img;

	//Hooks membres variables // to do
	double	escape_value; // Hypotenuse
	int		iterations_definition; //value tight with the image quality and rendering speed
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

//strings_utils
int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);
double	atodbl(char *s);

//** init **
void	fractal_init(t_fractal *fractal);

//** render **
void	fractal_render(t_fractal *fractal);

//** math **
double		map(int value, double new_min, double new_max, double old_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//**hooks_events**
int	key_handler(int keysym, t_fractal *fractal);

//** clean_up **
int	close_handler(t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);

#endif