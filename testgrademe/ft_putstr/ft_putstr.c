/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:20:13 by michhern          #+#    #+#             */
/*   Updated: 2024/04/23 14:24:58 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <unistd.h>
#include <string.h>
*/
 void    ft_putstr(char *str)
 {
 	char    *addres;
 	int     i;

 	addres = str;
 	i = 0;
 	while (addres[i] != '\0')
 	{
		write(1, &addres[i], 1);
 		i++;
 	}
 }
 
/*int   main(void)
{
	char    *str;

	str = "Hola, como estas";
   	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}*/
