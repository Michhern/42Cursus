/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:25:55 by michhern          #+#    #+#             */
/*   Updated: 2025/01/10 11:58:21 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*int	main(int ac, char *av[])
{
	char	*str;
	int		len;

	if (ac == 2)
	{
		str = av[1];
		len = ft_strlen(str);
		printf("the length of the string is %d\n", len);
	}
	else
		printf("Error: %s <string>\n", av[0]);
	return (0);
}*/

/*int	main(void)
{
	char	*str;
	int		len;

	str = "Hi how are you";
	len	= ft_strlen(str);
	printf("The length of this estring is %d\n", len);
	return (0);
}*/
