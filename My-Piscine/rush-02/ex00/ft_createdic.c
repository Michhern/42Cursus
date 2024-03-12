/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createdic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:29:14 by michhern          #+#    #+#             */
/*   Updated: 2023/12/10 19:39:32 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char ***ft_createdic(nuembers.dict)
{
	int		rd1;
	char	buffer[1050];
	int		i;
	char ***dic;
	int		j;

	i = 0;
	j = 0;
	rd1 = open("numbers.dic", O_RDONLY);//Abrimos el archivo
	rd1 = read("numbers.dic", O_RDONLY);//Leemos los archivos

	dic =  malloc(42 * sizeof(**char));
	while(i < 42)
	{
		dic[i] = malloc(2 * sizeof(*char));
		while(j < 2)
		{
			dic[i][j] = malloc(50 * sizeof(char));
			j++;
		}
		i++;
	}
	while (read(rd1, &buffer, sizeof(buffer)))
	{
		write()
	}
}
