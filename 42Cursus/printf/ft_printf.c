/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:26:52 by michhern          #+#    #+#             */
/*   Updated: 2024/03/12 12:22:03 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

if (format = 'p')
{
	write(1, "0x", 2);
	ft_hexadecimal(nbr, format);
}
if (format = 'X' || format == 'x')
{
	ft_hexadecimal(nbr, format);
}
if (format = 'd' || format == 'i')
{
	ft_putnbr(nbr);
}