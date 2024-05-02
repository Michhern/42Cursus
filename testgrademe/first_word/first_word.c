/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:17:36 by michhern          #+#    #+#             */
/*   Updated: 2024/05/02 15:21:45 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		first;
	char	*str;

	first = 0;
	str = argv[1];
	if (argc == 2)
	{
		while (str[first] == '\t' || str[first] == ' ')
			first++;
		while (str[first] != '\t' && str[first] != ' ' && str[first])
		{
			write(1, &str[first], 1);
			first++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
