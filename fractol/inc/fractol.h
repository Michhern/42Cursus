/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:40:07 by michhern          #+#    #+#             */
/*   Updated: 2024/12/10 19:45:05 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH					800
# define HEIGHT					800
# define BLACK					0x000000
# define WHITE					0xFFFFFF
# define RED					0xFF0000
# define GREEN					0x00FF00
# define BLUE					0x0000FF
# define MAGENTA_BURST			0xFF00FF
# define LIME_SHOCK				0xCCFF00
# define NEON_ORANGE			0xFF6600
# define PSYCHEDELIC_PURPLE 	0x660066
# define AQUA_DREAM				0x33CCCC
# define HOT_PINK				0xFF66B2
# define ELECTRIC_BLUE			0x0066FF
# define LAVA_RED				0xFF3300
# define DEFAULT_ESCAPE_VALUE	4.0
# define DEFAULT_ITERATIONS		42
# define DEFAULT_ZOOM			1.0
# define FRACTAL_JULIA			1
# define FRACTAL_MANDELBROT		2
# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \
	\n\t\"./fractol julia <value_1> <value_2>\"\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../mlx-linux/mlx.h"

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	int		type;
	char	*name;
	void	*mlx_connection;
	void	*mlx_windows;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		atodbl(char *s);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		malloc_error(const char *context);
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
double		map(int value, double new_min, double new_max, double old_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif