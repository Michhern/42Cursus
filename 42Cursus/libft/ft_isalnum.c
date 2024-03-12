/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:20:36 by michhern          #+#    #+#             */
/*   Updated: 2024/02/06 14:04:51 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
{
	if ((alnum >= 'A' && alnum <= 'Z') || (alnum >= 'a' && alnum <= 'z')
		|| (alnum >= '0' && alnum <= '9'))
		return (1);
	else
		return (0);
}
