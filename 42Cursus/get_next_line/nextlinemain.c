/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextlinemain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:48:42 by michhern          #+#    #+#             */
/*   Updated: 2024/04/09 11:41:41 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		count;

	if (argc != 2)
	{
		printf("Uso: %s <nombre_archivo>\n", argv[0]);
		return (1);
	}
	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("Line %d: %s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
