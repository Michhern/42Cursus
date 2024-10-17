/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:33:28 by michhern          #+#    #+#             */
/*   Updated: 2024/07/24 16:46:09 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*str;
	int		i;

	str = lst;
	i = 0;
	while (str != NULL)
	{
		str = str->next;
		i++;
	}
	return (i);
}
