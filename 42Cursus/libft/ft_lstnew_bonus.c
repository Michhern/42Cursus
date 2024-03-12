/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michhern <michhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:57:30 by michhern          #+#    #+#             */
/*   Updated: 2024/02/13 17:14:27 by michhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*data;

	data = malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (data);
}

/*int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Hi let's check this function");
	if (node != NULL)
	{
		printf("Nuevo node creado con exito.\n");
		printf("%s\n", (char *)node->content);
	}
	else
	{
		printf("Error: No se pudo crear el node.\n");
	}
	free(node);
	return (0);
}*/
