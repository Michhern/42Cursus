/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:16:54 by michhern          #+#    #+#             */
/*   Updated: 2024/12/02 13:38:29 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
* [0..799] -> [-2..+2]
*/
/*double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) *(unscaled_num - old_min) / (old_max - old_min) + new_min); 
}*/

/*Version de la funcion anerior*/
double	map(int value, double new_min, double new_max, double old_range)
{
	return (new_min + ((double)(value / old_range) * (new_max - new_min)));
}

/*
* SUM complex
*/
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
* SQUARE is trikier
*
* real = (x^2 - y^2)
* i = 2 * x * y
*/
t_complex	square_complex(t_complex z)
{
	t_complex result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
