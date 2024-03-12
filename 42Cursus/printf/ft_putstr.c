/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:09 by michhern          #+#    #+#             */
/*   Updated: 2024/03/07 13:39:32 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	amount;

	amount = 0;
	while (*str)
	{
		amount = ft_putchar(*str);
		if (amount == -1)
			return (-1);
	}
	return (amount);
}
