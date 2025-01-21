/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:56:01 by michhern          #+#    #+#             */
/*   Updated: 2024/07/04 18:03:46 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	msg_wrong(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(2, str, i);
	exit (EXIT_FAILURE);
}

char	*str2(char *s)
{
	static char	*str;

	if (s != NULL)
	{
		write_msg(s);
		free(s);
		s = NULL;
		str = s;
	}
	return (str);
}

void	write_msg(char *str)
{
	static int	i;

	i = ft_strlen(str);
	write(1, str, i);
	i = 0;
}
