/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:49:52 by michhern          #+#    #+#             */
/*   Updated: 2024/04/29 17:53:50 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	f;

	f = 1;
	while (f >= 1 && f <= 100)
	{
		if (f % 3 == 0 && f % 5 == 0)
			printf("fizzbuzz\n");
		else if (f % 3 == 0)
			printf("fizz\n");
		else if (f % 5 == 0)
			printf("buzz\n");
		else
			printf("%d\n", f);
		f++;
	}
	return (0);
}
