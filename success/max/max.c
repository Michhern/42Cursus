/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:17:32 by michhern          #+#    #+#             */
/*   Updated: 2025/01/09 12:03:59 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				result;

	i = 0;
	if (len == 0)
		return (0);
	result = tab[i];
	while (i < len)
	{
		if (result < tab[i])
			result = tab[i];
		i++;
	}
	return (result);
}
/*#include <stdio.h>

int max(int *tab, unsigned int len);

int main(void)
{
    int tab[] = {42, 56, 88, 7, 56, 88, 100, 12, 34};
    unsigned int len = sizeof(tab) / sizeof(tab[0]);
    int result;

    result = max(tab, len);
    if (len == 0)
	{
        printf("Array is empty. Max value: 0\n");
	}
	else
	{
        printf("Max value in the array: %d\n", result);
	}
	return (0);
}*/
