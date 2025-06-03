/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micheher <micheher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:50:13 by micheher          #+#    #+#             */
/*   Updated: 2025/06/03 12:42:28 by micheher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_liatnew(void *content)
{
	t_list *data;

	data = malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (NULL);
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