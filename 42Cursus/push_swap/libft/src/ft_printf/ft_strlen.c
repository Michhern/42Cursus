/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:10:45 by michhern          #+#    #+#             */
/*   Updated: 2024/07/26 15:14:00 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	leng;

	if (!str)
		return (-1);
	leng = 0;
	while (str[leng] != '\0')
		leng++;
	return (leng);
}
