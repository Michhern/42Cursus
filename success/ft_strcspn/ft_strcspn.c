/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:09:05 by michhern          #+#    #+#             */
/*   Updated: 2024/06/17 18:50:15 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	pos_s;
	size_t	pos_rej;

	pos_s = 0;
	pos_rej = 0;
	while (s[pos_s] != '\0')
	{
		while (reject[pos_rej] != '\0')
		{
			if (reject[pos_rej] == s[pos_s])
				return (pos_s);
			pos_rej++;
		}
		pos_rej = 0;
		pos_s++;
	}
	return (pos_s);
}

/*int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("Cadena 1: %s\n", av[1]);
		printf("Cadena 2: %s\n", av[2]);
		printf("strcspn: %zu\n", strcspn(av[1], av[2]));
		printf("strcspn: %zu\n", ft_strcspn(av[1], av[2]));
	}
	return (0);
}*/

/*int	main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <string> <reject>\n", argv[0]);
        return 1;
    }

    const char	*s = argv[1];
    const char	*reject = argv[2];

    size_t	result = ft_strcspn(s, reject);
    printf("The length of the initial segment of %s which 
does not contain any of the characters in %s is: %zu\n", s, reject, result);
    return (0);
}*/
