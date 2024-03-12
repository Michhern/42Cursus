/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:24:35 by michhern          #+#    #+#             */
/*   Updated: 2023/12/11 20:11:39 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	p;

	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		p = 0;
		while (str[i + p] == to_find[p] && to_find[p] != '\0')
		{
			p++;
		}
		if (to_find[p] == '\0')
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
